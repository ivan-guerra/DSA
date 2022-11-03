cmake_minimum_required(VERSION 3.13...3.22)

project(queue DESCRIPTION "Queue"
              LANGUAGES   CXX
)

add_library(${PROJECT_NAME} INTERFACE)

target_include_directories(${PROJECT_NAME}
    INTERFACE
       "${DS_INCLUDE_DIR}/Queue"
)

target_compile_options(${PROJECT_NAME}
    INTERFACE
        -Wall
        -Werror
        -Wextra
        "$<$<CONFIG:DEBUG>:-O0;-g3;-ggdb>"
)

target_compile_features(${PROJECT_NAME}
    INTERFACE
        cxx_std_17
)
