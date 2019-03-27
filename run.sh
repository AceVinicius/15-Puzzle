#!/bin/bash

# Remove, if already created build folder
rm -r build


# Compile 15 Puzzle
mkdir build
cd ./build
cmake ../
make
./15puzzle