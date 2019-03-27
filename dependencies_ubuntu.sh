#!/bin/bash

# Install dependencies
sudo apt install cmake
sudo apt install SDL2*

sudo apt update
sudo apt upgrade


# Compile and run 15 Puzzle
bash run.sh
