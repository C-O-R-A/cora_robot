import sys
if sys.prefix == '/usr':
    sys.real_prefix = sys.prefix
    sys.prefix = sys.exec_prefix = '/home/matth/Desktop/Colossus/Software/cora_robot/src/install/cora_moveit'
