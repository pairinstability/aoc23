#!/bin/sh

if [ ! -d "build" ]; then
    echo "build dir doesn't exist"
    exit 1
fi

cd build
ctest -V
