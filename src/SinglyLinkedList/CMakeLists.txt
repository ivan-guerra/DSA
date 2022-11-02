cmake_minimum_required(VERSION 3.13...3.22)

project(singly_linked_list DESCRIPTION "Singly Linked List"
                          LANGUAGES   CXX
)

add_executable(${PROJECT_NAME} singly_linked_list.cc)

target_include_directories(${PROJECT_NAME}
    PUBLIC
       "${DS_INCLUDE_DIR}/SinglyLinkedList"
)

target_compile_options(${PROJECT_NAME}
    PRIVATE
        -Wall
        -Werror
        -Wextra
        "$<$<CONFIG:DEBUG>:-O0;-g3;-ggdb>"
)

target_compile_features(${PROJECT_NAME}
    PRIVATE
        cxx_std_17
)

# Install the UDP socket comm binary to udp_comm_test/bin
set(DS_INSTALL_DIR "${CMAKE_SOURCE_DIR}/bin")
install(TARGETS ${PROJECT_NAME}
    RUNTIME DESTINATION ${DS_INSTALL_DIR}
)
