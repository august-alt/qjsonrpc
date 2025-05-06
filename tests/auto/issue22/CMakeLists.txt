set(CMAKE_AUTOMOC ON)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(TEST_NAME
    tst_issue22
)

set(SOURCES
    tst_issue22.cpp
)

add_library_test(${TEST_NAME} ${TEST_NAME} ${SOURCES})
