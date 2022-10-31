#!/bin/bash

# Source the project configuration.
source config.sh

# Set to "Debug" if you would like to the binary to include debug info.
CMAKE_BUILD_TYPE="Release"

Build()
{
    mkdir -pv $DS_BUILD_DIR

    # Build and install the kernel.
    pushd $DS_BUILD_DIR
        cmake -DCMAKE_BUILD_TYPE=$CMAKE_BUILD_TYPE ../ && \
        make -j$(nproc) all && \
        make install
    popd
}

Build
