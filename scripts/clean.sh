#!/bin/bash

LGREEN='\033[1;32m'
NC='\033[0m'

# Source the project configuration.
source config.sh

# Remove the binary directory.
if [ -d $DS_BIN_DIR ]
then
    echo -e "${LGREEN}Removing '$DS_BIN_DIR'${NC}"
    rm -r $DS_BIN_DIR
fi

# Remove the CMake build directory.
if [ -d $DS_BUILD_DIR ]
then
    echo -e "${LGREEN}Removing '$DS_BUILD_DIR'${NC}"
    rm -r $DS_BUILD_DIR
fi
