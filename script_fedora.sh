#!/bin/bash


sudo dnf install cmake
sudo dnf install SDL2*


sudo dnf update
sudo dnf upgrade


mkdir build
cd ./build
cmake ../
make
./15puzzle
