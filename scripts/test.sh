#!/bin/bash

# This script calls ctest to run all project unit tests. The script accepts a
# single argument which is a filtering regex describing the name of the test(s)
# to be run. Be sure to quote your input if using wildcards or other regex
# syntax.
# usage: test.sh [TEST_NAME_REGEX]

source config.sh

RunTests()
{
    if [ ! -d $DS_TEST_DIR ]
    then
        echo -e "${LRED}error missing ${1} test dir${NC}"
        echo -e "${LRED}did you forget to run 'build.sh'?${NC}"
        exit 1
    fi

    pushd $DS_TEST_DIR > /dev/null
        ctest -R $1
    popd > /dev/null
}

RunTests $1
