set(CMAKE_AUTOMOC ON)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(TEST_NAME
    tst_qjsonrpcmessage
)

set(SOURCES
    tst_qjsonrpcmessage.cpp
)

add_library_test(${TEST_NAME} ${TEST_NAME} ${SOURCES})
