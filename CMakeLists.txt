cmake_minimum_required(VERSION 3.13...3.22)

project(data_structures
    VERSION 1.0
    DESCRIPTION "Toy implementations of classic data structures."
)

set(DS_INCLUDE_DIR "${CMAKE_SOURCE_DIR}/include"
    CACHE STRING "${PROJECT_NAME} include directory.")

add_subdirectory(src)
