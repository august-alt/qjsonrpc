set(CMAKE_AUTOMOC ON)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(TEST_NAME
    tst_httpclient
)

set(HEADERS
    testhttpserver.h
)

set(SOURCES
    testhttpserver.cpp
    tst_qjsonrpchttpclient.cpp
)

set(SOURCES ${SOURCES} ${HEADERS})

add_library_test(${TEST_NAME} ${TEST_NAME} ${SOURCES})
