#!/bin/bash

# Source the project configuration.
source config.sh

# Set to "Debug" if you would like the binary to include debug info.
CMAKE_BUILD_TYPE="Release"
CMAKE_INSTALL_PREFIX=$DS_BIN_DIR

Build()
{
    mkdir -pv $DS_BUILD_DIR

    # Build and install the kernel.
    pushd $DS_BUILD_DIR
        cmake \
            -DCMAKE_BUILD_TYPE=$CMAKE_BUILD_TYPE \
            -DCMAKE_INSTALL_PREFIX=$CMAKE_INSTALL_PREFIX \
            ../ && \
        make -j$(nproc) all && \
        make install
    popd
}

Build
