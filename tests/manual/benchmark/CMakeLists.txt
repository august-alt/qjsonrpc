set(CMAKE_AUTOMOC ON)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(TEST_NAME
    benchmark
)

set(SOURCES
    tst_benchmark.cpp
)

add_executable(${TEST_NAME} ${SOURCES})

target_link_libraries(${TEST_NAME} PRIVATE Qt5::Core Qt5::Network Qt5::Test)
target_link_libraries(${TEST_NAME} PRIVATE PkgConfig::HTTPParser)

target_include_directories(${TEST_NAME} PRIVATE "${QJSONRPC_INCLUDE_DIRS}/qjsonrpc")
target_link_libraries(${TEST_NAME} PRIVATE ${QJSONRPC_LIBRARIES})
