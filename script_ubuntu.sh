#!/bin/bash


sudo apt install cmake
sudo apt install SDL2*


sudo apt update
sudo apt upgrade


mkdir build
cd ./build
cmake ../
make
./15puzzle
