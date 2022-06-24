#! /bin/bash

cd build
rm CMakeCache.txt
cmake ..
make clean
make
./cpplox