cmake_minimum_required(VERSION 3.13...3.22)

set(TESTNAME vector_test)

add_executable(${TESTNAME} vector_test.cc vector_test_fixture.cc)

target_link_libraries(${TESTNAME}
    PRIVATE
        gtest_main
        vector
)

gtest_discover_tests(${TESTNAME}
        WORKING_DIRECTORY ${PROJECT_DIR}
        PROPERTIES VS_DEBUGGER_WORKING_DIRECTORY "${PROJECT_DIR}"
)

set_target_properties(${TESTNAME}
    PROPERTIES FOLDER tests
)
