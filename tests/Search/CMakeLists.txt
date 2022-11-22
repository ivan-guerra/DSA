cmake_minimum_required(VERSION 3.13...3.22)

set(TESTNAME search_test)

add_executable(${TESTNAME} search_test.cc search_test_fixture.cc)

target_link_libraries(${TESTNAME}
    PRIVATE
        gtest_main
        search
)

gtest_discover_tests(${TESTNAME}
        WORKING_DIRECTORY ${PROJECT_DIR}
        PROPERTIES VS_DEBUGGER_WORKING_DIRECTORY "${PROJECT_DIR}"
)

set_target_properties(${TESTNAME}
    PROPERTIES FOLDER tests
)
