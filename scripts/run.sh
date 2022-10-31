#!/bin/bash

# This script runs the driver program passed as its first argument.
# usage: run.sh DRIVER_PROG
# For example, 'run.sh array' will run the array driver program.

source config.sh

Run()
{
    if [ ! -d $DS_BIN_DIR ]
    then
        echo -e "${LRED}error missing ${1} binary dir${NC}"
        echo -e "${LRED}did you forget to run 'build.sh'?${NC}"
        exit 1
    fi

    pushd $DS_BIN_DIR > /dev/null
        ./$1
    popd > /dev/null
}

Run $1
