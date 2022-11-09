cmake_minimum_required(VERSION 3.13...3.22)

set(TESTNAME hashtable_test)

add_executable(${TESTNAME} hashtable_test.cc hashtable_test_fixture.cc)

target_link_libraries(${TESTNAME}
    PRIVATE
        gtest_main
        hashtable
)

gtest_discover_tests(${TESTNAME}
        WORKING_DIRECTORY ${PROJECT_DIR}
        PROPERTIES VS_DEBUGGER_WORKING_DIRECTORY "${PROJECT_DIR}"
)

set_target_properties(${TESTNAME}
    PROPERTIES FOLDER tests
)
