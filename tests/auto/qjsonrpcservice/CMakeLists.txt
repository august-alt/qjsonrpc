set(CMAKE_AUTOMOC ON)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(TEST_NAME
    tst_qjsonrpcservice
)

set(SOURCES
    tst_qjsonrpcservice.cpp
)

add_library_test(${TEST_NAME} ${TEST_NAME} ${SOURCES})
