#!/bin/bash

cd lib
# Remove, if already created build folder
rm -r ./cmake/build

# Compile 15 Puzzle
mkdir ./cmake/build
cd ./cmake/build
cmake ../
make
mv 15_Puzzle ../../../bin
../../../bin/15_Puzzle
