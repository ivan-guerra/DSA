# Data Structures and Algorithms

This project contains implementations of common data structures and algorithms.
Unit tests for each DSA are included.

### Building and Running Unit Tests

To build this project you'll need CMake3.13+ and a C++ compiler supporting
C++17 features. This project uses
[GoogleTest](https://github.com/google/googletest) as its unit testing
framework. GoogleTest is included as a submodule. Make sure you clone/pull the
GoogleTest submodule before your begin.

The [scripts/](scripts) directory contains the build and run scripts. Change
directory to [scripts/](scripts).
```
cd scripts/
```

To build all tests.
```
./build.sh
```

To run all tests.
```
./test.sh
```
Note, you can run a specific test suite by passing `test.sh` the name of the
test suite. For example, to run all the tests in the `SortTest` suite:
```
./test.sh SortTest
```
