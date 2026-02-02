from setuptools import find_packages
from setuptools import setup

setup(
    name='cora_msgs',
    version='0.0.0',
    packages=find_packages(
        include=('cora_msgs', 'cora_msgs.*')),
)
