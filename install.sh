
git clone https://github.com/C-O-R-A/CoDI.git
sudo apt install ros-jazzy-moveit
sudo apt install ros-jazzy-moveit-py
sudo rosdep-install
pip install requirements.txt
sudo apt update && sudo apt upgrade
cd .. && colcon build

# run with: './install.sh'