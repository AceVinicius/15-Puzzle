#!/bin/bash


sudo apt install make
sudo apt install cmake
sudo apt install SDL2*


sudo apt update
sudo apt upgrade


rm -r build

mkdir build
cd ./build
cmake ../
make
./15puzzle
