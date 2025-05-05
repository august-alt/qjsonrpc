set(CMAKE_AUTOMOC ON)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(TEST_NAME
    tst_qjsonrpcserver
)

set(HEADERS
    testservices.h
)

set(SOURCES
    testservices.cpp
    tst_qjsonrpcserver.cpp
)

set(SOURCES ${SOURCES} ${HEADERS})

add_library_test(${TEST_NAME} ${TEST_NAME} ${SOURCES})
