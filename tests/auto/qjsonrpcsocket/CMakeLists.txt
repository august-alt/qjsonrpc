set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(TEST_NAME
    tst_qjsonrpcsocket
)

set(SOURCES
    tst_qjsonrpcsocket.cpp
)

set(RESOURCES
    tst_qjsonrpcsocket.qrc
)

set(SOURCES ${SOURCES} ${RESOURCES})

add_library_test(${TEST_NAME} ${TEST_NAME} ${SOURCES})
target_include_directories(${TEST_NAME} PRIVATE "${CMAKE_SOURCE_DIR}/src/")
