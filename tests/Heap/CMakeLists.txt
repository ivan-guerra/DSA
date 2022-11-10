cmake_minimum_required(VERSION 3.13...3.22)

set(TESTNAME heap_test)

add_executable(${TESTNAME} heap_test.cc heap_test_fixture.cc)

target_link_libraries(${TESTNAME}
    PRIVATE
        gtest_main
        heap
)

gtest_discover_tests(${TESTNAME}
        WORKING_DIRECTORY ${PROJECT_DIR}
        PROPERTIES VS_DEBUGGER_WORKING_DIRECTORY "${PROJECT_DIR}"
)

set_target_properties(${TESTNAME}
    PROPERTIES FOLDER tests
)
