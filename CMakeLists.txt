cmake_minimum_required(VERSION 3.14)

project(QJSonRPC)
set(CMAKE_CXX_STANDARD 14)

set(QJSONRPC_VERSION "1.1.1")

set(QJSONRPC_VERSION_MAJOR "1")
set(QJSONRPC_VERSION_MINOR "1")
set(QJSONRPC_VERSION_PATCH "1")

set(QJSONRPC_IN_BUILD_TREE TRUE)

set(CMAKE_MODULE_PATH ${CMAKE_SOURCE_DIR}/cmake)

if(UNIX)
  include(GNUInstallDirs)
else()
  if (WIN32)
    set(${CMAKE_INSTALL_LIBDIR} "lib")
    set(${CMAKE_INSTALL_DATADIR} "share")
    set(${CMAKE_INSTALL_INCLUDEDIR} "include")
    set(${CMAKE_INSTALL_BINDIR} "bin")
    message(STATUS "Setting installation destination on Windows to: ${CMAKE_INSTALL_PREFIX}")
  else()
    message(FATAL_ERROR "System not UNIX nor WIN32 - not implemented yet")
  endif()
endif()

# configure and install QJSonRPCConfig.cmake file
configure_file(
    "${CMAKE_MODULE_PATH}/QJSonRPCConfig.cmake.in"
    "${CMAKE_BINARY_DIR}/QJSonRPCConfig.cmake"
    IMMEDIATE @ONLY
)
install(FILES ${CMAKE_BINARY_DIR}/QJSonRPCConfig.cmake DESTINATION "${CMAKE_INSTALL_LIBDIR}/QJSonRPC")

configure_file(
    "${CMAKE_MODULE_PATH}/QJSonRPCBuildTreeSettings.cmake.in"
    "${CMAKE_BINARY_DIR}/QJSonRPCBuildTreeSettings.cmake"
    IMMEDIATE @ONLY
)

include("${CMAKE_BINARY_DIR}/QJSonRPCConfig.cmake")

export(PACKAGE QJSonRPC)

option(QJSONRPC_BUILD_TESTS "Build the QJSonRPC tests." OFF)

add_subdirectory(src)

enable_testing()
add_subdirectory(tests)
