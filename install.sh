#!/usr/bin/env bash
set -euo pipefail

ROOT="$(cd "$(dirname "${BASH_SOURCE[0]}")/.." && pwd)"
SRC_DIR="$ROOT/src"
BASHRC="$HOME/.bashrc"
ROS_DISTRO="${ROS_DISTRO:-jazzy}"

# Crystal on the Waveshare RS485 CAN HAT — current production units use 12MHz,
# older units use 8MHz. Check the crystal printed on the board and override
# with CAN_OSCILLATOR=8000000 if needed.
CAN_OSCILLATOR="${CAN_OSCILLATOR:-12000000}"
CAN_BITRATE="${CAN_BITRATE:-250000}"
NEEDS_REBOOT=0

if [ ! -d "$SRC_DIR" ]; then
echo "ERROR: expected workspace root at $ROOT with a src/ folder."
exit 1
fi

if [ "$(id -u)" -eq 0 ]; then
echo "WARNING: running as root is not recommended. The script will still use sudo for system installs."
fi

echo "Workspace root: $ROOT"
echo "ROS distro: $ROS_DISTRO"

if [ -f "$ROOT/.gitmodules" ] || [ -f "$SRC_DIR/.gitmodules" ]; then
echo "Updating git submodules..."
git submodule update --init --recursive
fi

echo "Configuring CAN HAT (MCP2515, oscillator=${CAN_OSCILLATOR}Hz)..."

if [ -f /boot/firmware/config.txt ]; then
CONFIG_TXT="/boot/firmware/config.txt"
elif [ -f /boot/config.txt ]; then
CONFIG_TXT="/boot/config.txt"
else
echo "WARNING: could not find /boot/firmware/config.txt or /boot/config.txt — skipping CAN HAT setup."
CONFIG_TXT=""
fi

if [ -n "$CONFIG_TXT" ]; then
if [ "$CAN_OSCILLATOR" = "12000000" ]; then
CAN_SPI_MAX_FREQ="2000000"
else
CAN_SPI_MAX_FREQ="1000000"
fi

if ! grep -q "^dtparam=spi=on" "$CONFIG_TXT"; then
echo "dtparam=spi=on" | sudo tee -a "$CONFIG_TXT" > /dev/null
NEEDS_REBOOT=1
fi

if ! grep -q "dtoverlay=mcp2515-can0" "$CONFIG_TXT"; then
echo "dtoverlay=mcp2515-can0,oscillator=${CAN_OSCILLATOR},interrupt=25,spimaxfrequency=${CAN_SPI_MAX_FREQ}" | sudo tee -a "$CONFIG_TXT" > /dev/null
NEEDS_REBOOT=1
echo "Added mcp2515-can0 overlay to $CONFIG_TXT — a reboot is required before can0 will exist."
else
echo "mcp2515-can0 overlay already present in $CONFIG_TXT — skipping."
fi
fi

echo "Installing systemd service to bring up can0 on every boot..."
CAN_SERVICE="/etc/systemd/system/can0-up.service"
sudo tee "$CAN_SERVICE" > /dev/null <<EOF
[Unit]
Description=Bring up can0 (MCP2515 CAN HAT) at ${CAN_BITRATE} bps
After=network-pre.target
Wants=network-pre.target
Before=network.target

[Service]
Type=oneshot
RemainAfterExit=yes
ExecStartPre=-/sbin/ip link set can0 down
ExecStart=/sbin/ip link set can0 type can bitrate ${CAN_BITRATE}
ExecStart=/sbin/ip link set can0 up

[Install]
WantedBy=multi-user.target
EOF
sudo systemctl daemon-reload
sudo systemctl enable can0-up.service

echo "Waiting for any existing apt/dpkg lock to clear (e.g. unattended-upgrades)..."
LOCK_WAIT=0
while sudo fuser /var/lib/dpkg/lock-frontend >/dev/null 2>&1; do
if [ "$LOCK_WAIT" -eq 0 ]; then
echo "apt/dpkg lock is held — waiting (will stop unattended-upgrades after 60s if still stuck)..."
fi
sleep 5
LOCK_WAIT=$((LOCK_WAIT + 5))
if [ "$LOCK_WAIT" -ge 60 ]; then
echo "Lock still held after 60s — stopping unattended-upgrades to unblock install."
sudo systemctl stop unattended-upgrades || true
break
fi
done

echo "Refreshing ROS 2 apt source (handles ROS's periodic signing-key rotation)..."
if ! command -v curl >/dev/null 2>&1; then
sudo apt install -y curl
fi
if ! dpkg -s ros2-apt-source >/dev/null 2>&1; then
ROS_APT_SOURCE_VERSION="$(curl -s https://api.github.com/repos/ros-infrastructure/ros-apt-source/releases/latest | grep -F "tag_name" | awk -F\" '{print $4}')"
curl -L -o /tmp/ros2-apt-source.deb "https://github.com/ros-infrastructure/ros-apt-source/releases/download/${ROS_APT_SOURCE_VERSION}/ros2-apt-source_${ROS_APT_SOURCE_VERSION}.$(. /etc/os-release && echo $VERSION_CODENAME)_all.deb"
sudo apt install -y /tmp/ros2-apt-source.deb
fi

sudo apt update
sudo apt install -y \
python3-pip \
python3-colcon-common-extensions \
python3-rosdep \
python3-vcstool \
python3-rosinstall-generator \
ros-${ROS_DISTRO}-desktop \
ros-${ROS_DISTRO}-ros2-control \
ros-${ROS_DISTRO}-ros2-controllers \
ros-${ROS_DISTRO}-moveit \
ros-${ROS_DISTRO}-moveit-py \
ros-${ROS_DISTRO}-moveit-servo \
can-utils

sudo apt upgrade -y

python3 -m pip install --upgrade pip --break-system-packages

sudo rosdep update
rosdep install --from-paths "$SRC_DIR" --ignore-src -r -y

if [ -f "$SRC_DIR/requirements.txt" ]; then
python3 -m pip install -r "$SRC_DIR/requirements.txt" --break-system-packages
fi
if [ -f "$SRC_DIR/cora_common/requirements.txt" ]; then
python3 -m pip install -r "$SRC_DIR/cora_common/requirements.txt" --break-system-packages
fi
if [ -f "$ROOT/requirements.txt" ]; then
python3 -m pip install -r "$ROOT/requirements.txt" --break-system-packages
fi

source "/opt/ros/${ROS_DISTRO}/setup.bash"
if ! grep -Fxq "source /opt/ros/${ROS_DISTRO}/setup.bash" "$BASHRC"; then
echo "source /opt/ros/${ROS_DISTRO}/setup.bash" >> "$BASHRC"
fi

if [ -f "$ROOT/install/setup.bash" ]; then
source "$ROOT/install/setup.bash"
if ! grep -Fxq "source $ROOT/install/setup.bash" "$BASHRC"; then
echo "source $ROOT/install/setup.bash" >> "$BASHRC"
fi
fi

if [ "$NEEDS_REBOOT" -eq 1 ]; then
echo ""
echo "=============================================================="
echo "REBOOT REQUIRED: CAN HAT config was just added to $CONFIG_TXT."
echo "Run 'sudo reboot' — can0 will come up automatically at boot"
echo "from now on via the can0-up.service that was just installed."
echo "=============================================================="
elif ip link show can0 &> /dev/null; then
echo "Starting can0-up.service..."
sudo systemctl start can0-up.service
else
echo "WARNING: can0 not found and no config changes were made this run — check CAN HAT wiring/seating."
fi

echo "Install complete. Run 'source /opt/ros/${ROS_DISTRO}/setup.bash' and 'source $ROOT/install/setup.bash' to use the workspace."