if (NOT ${QJSONRPC_BUILD_TESTS})
  return()
endif()

find_package(Qt5 COMPONENTS Core Network Test REQUIRED)

find_package(PkgConfig REQUIRED)
pkg_check_modules(HTTPParser REQUIRED IMPORTED_TARGET http_parser)

macro(add_library_test test_name test_executable)
    add_executable(${test_executable}
        ${ARGN}
    )
    target_link_libraries(${test_executable} PRIVATE Qt5::Core Qt5::Network Qt5::Test)
    target_link_libraries(${test_executable} PRIVATE PkgConfig::HTTPParser)

    target_include_directories(${test_executable} PRIVATE "${QJSONRPC_INCLUDE_DIRS}/qjsonrpc")
    target_link_libraries(${test_executable} PRIVATE ${QJSONRPC_LIBRARIES})

    add_test(NAME ${test_name} COMMAND ${test_executable})
endmacro(add_library_test)

add_subdirectory(auto)
add_subdirectory(manual)
