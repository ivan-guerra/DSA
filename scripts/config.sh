#!/bin/bash

GREEN='\033[1;32m'
LRED='\033[1;31m'
NC='\033[0m'

# Root directory.
DS_PROJECT_PATH=$(dirname $(pwd))

# Scripts directory.
DS_SCRIPTS_PATH="${DS_PROJECT_PATH}/scripts"

# Binary directory.
DS_BIN_DIR="${DS_PROJECT_PATH}/bin"

# Build directory.
DS_BUILD_DIR="${DS_PROJECT_PATH}/build"

# Test directory.
DS_TEST_DIR=$DS_BUILD_DIR
