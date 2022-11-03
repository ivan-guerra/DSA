cmake_minimum_required(VERSION 3.13...3.22)

set(TESTNAME stack_test)

add_executable(${TESTNAME} stack_test.cc stack_test_fixture.cc)

target_compile_options(${TESTNAME}
    PRIVATE
        -Wno-uninitialized
)

target_link_libraries(${TESTNAME}
    PRIVATE
        gtest_main
        stack
)

gtest_discover_tests(${TESTNAME}
        WORKING_DIRECTORY ${PROJECT_DIR}
        PROPERTIES VS_DEBUGGER_WORKING_DIRECTORY "${PROJECT_DIR}"
)

set_target_properties(${TESTNAME}
    PROPERTIES FOLDER tests
)
