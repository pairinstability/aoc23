#!/bin/sh

if [ ! -d "build" ]; then
    mkdir build
fi

cd build
CXX=/usr/bin/g++-12 cmake -G Ninja ..
ninja
cd ..

#./run.sh
