#!/usr/bin/bash
sudo apt-get update
sudo apt-get install git
cd ~/
mkdir Projects
cd Projects
git clone https://github.com/CGAL/cgal.git
cd cgal
git checkout -b CGAL4_10 releases/CGAL-4.10
sudo apt-get install -y cmake
sudo apt install -y cmake-qt-gui
cd ~/
wget https://download.qt.io/archive/qt/5.12/5.12.0/qt-opensource-linux-x64-5.12.0.run
chmod 755 qt-opensource-linux-x64-5.12.0.run
sudo apt-get update
sudo apt-get install -y freeglut3
sudo apt-get install -y freeglut3-dev
sudo apt-get install -y binutils-gold
sudo apt-get install -y g++
sudo apt-get install -y libglew-dev
sudo apt-get install -y mesa-common-dev
sudo apt-get install -y build-essential
sudo apt-get install -y libeigen3-dev
sudo apt-get install -y libboost-all-dev
sudo apt-get install -y libmpfr-dev
sudo apt-get install -y libgmp-dev
sudo apt-get install -y libtbb-dev
sudo apt-get install -y zlib1g-dev
cd ~/Projects/cgal
mkdir cgal-build 
mkdir cgal-install

