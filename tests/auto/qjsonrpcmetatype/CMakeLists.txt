set(CMAKE_AUTOMOC ON)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(TEST_NAME
    tst_qjsonrpcmetatype
)

set(SOURCES
    tst_qjsonrpcmetatype.cpp
)

add_library_test(${TEST_NAME} ${TEST_NAME} ${SOURCES})
