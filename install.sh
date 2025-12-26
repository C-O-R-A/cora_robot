
git clone https://github.com/C-O-R-A/CoDI.git

sudo apt install ros-jazzy-moveit
sudo apt install ros-jazzy-moveit-py
sudo rosdep-install

pip install -r requirements.txt

sudo apt update && sudo apt upgrade

cd .. && colcon build --symlink-install

source /opt/ros/jazzy/setup.bash
source /install/setup.bash
export LD_LIBRARY_PATH=/lib/x86_64-linux-gnu:/usr/lib/x86_64-linux-gnu:$LD_LIBRARY_PATH

# run with: './install.sh'

# NOTES
# To get the moveit setup assistant working in vscode, unset the gtk path using 'unset GTK_PATH'
#
# Make sure cmake file contains:
#
# install(
#   DIRECTORY
#       <folder_name>
#   DESTINATION share/${PROJECT_NAME}
# )
#
# Also make sure onshape config files are in the source root and point to 'description_pkg/meshes/' and not to 'meshes/'
# 
# if the setup assistant segfaults after clicking load model, install older rviz snapshot: https://github.com/moveit/moveit2/issues/3546#issuecomment-32666
#   wget http://snapshots.ros.org/jazzy/2025-05-23/ubuntu/pool/main/r/ros-jazzy-rviz-common/ros-jazzy-rviz-common_14.1.11-1noble.20250520.201719_amd64.deb
#
#   sudo apt --fix-broken install
#
#   sudo dpkg -i ros-jazzy-rviz-common_14.1.11-1noble.20250520.201719_amd64.deb
#
#
# You must add accell limits to joint limits config file
#
# End effector should have parent link L5, not end effector