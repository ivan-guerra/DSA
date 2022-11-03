cmake_minimum_required(VERSION 3.13...3.22)

project(data_structures
    VERSION 1.0
    DESCRIPTION "Header only implementations of classic data structures"
)

if(CMAKE_PROJECT_NAME STREQUAL PROJECT_NAME)
    option(PACKAGE_TESTS "Build Unit Tests" ON)
    if(PACKAGE_TESTS)
        enable_testing()
        include(GoogleTest)
        add_subdirectory(tests)
    endif()
endif()

add_subdirectory(include)
