set(CMAKE_AUTOMOC ON)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

find_package(Qt5 COMPONENTS Script REQUIRED)

set(TEST_NAME
    console
)

set(HEADERS
    interface.h
)

set(SOURCES
    interface.cpp
    main.cpp
)

set(SOURCES ${SOURCES} ${HEADERS})

add_executable(${TEST_NAME} ${SOURCES})

target_link_libraries(${TEST_NAME} PRIVATE Qt5::Core Qt5::Network)
target_link_libraries(${TEST_NAME} PRIVATE PkgConfig::HTTPParser)
target_link_libraries(${TEST_NAME} PRIVATE Qt5::Script)

target_include_directories(${TEST_NAME} PRIVATE "${QJSONRPC_INCLUDE_DIRS}/qjsonrpc")
target_link_libraries(${TEST_NAME} PRIVATE ${QJSONRPC_LIBRARIES})
