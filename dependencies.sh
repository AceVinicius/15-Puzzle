#!/bin/bash

# Install dependencies
sudo dnf install cmake
sudo dnf install SDL2*

sudo dnf update
sudo dnf upgrade


# Compile and run 15 Puzzle
bash run.sh
