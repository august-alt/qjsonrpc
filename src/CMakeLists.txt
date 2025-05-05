macro(add_qjsonrpc_library name)
  # add library
  add_library(${name} SHARED ${ARGN})
  set_target_properties(${name} PROPERTIES VERSION "${QJSONRPC_VERSION}" SOVERSION "${QJSONRPC_VERSION_MAJOR}")

  # add install target
  install(TARGETS ${name} DESTINATION ${CMAKE_INSTALL_LIBDIR}
      PERMISSIONS OWNER_READ OWNER_WRITE OWNER_EXECUTE GROUP_READ GROUP_EXECUTE WORLD_READ WORLD_EXECUTE)

  # copy library into build directory
  add_custom_command(TARGET ${name} POST_BUILD COMMAND
      ${CMAKE_COMMAND} ARGS -E copy
        $<TARGET_FILE:${name}>
        ${CMAKE_BINARY_DIR}/${CMAKE_INSTALL_LIBDIR}/$<TARGET_FILE_NAME:${name}>
      COMMENT "Copying library ${name} to output directory")

endmacro(add_qjsonrpc_library)

find_package(Qt5 COMPONENTS Core Network Gui REQUIRED)

find_package(PkgConfig REQUIRED)
pkg_check_modules(HTTPParser REQUIRED IMPORTED_TARGET http_parser)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(HEADERS
    qjsonrpcabstractserver.h
    qjsonrpcglobal.h
    qjsonrpchttpclient.h
    qjsonrpchttpserver.h
    qjsonrpclocalserver.h
    qjsonrpcmessage.h
    qjsonrpcmetatype.h
    qjsonrpcservice.h
    qjsonrpcserviceprovider.h
    qjsonrpcservicereply.h
    qjsonrpcsocket.h
    qjsonrpctcpserver.h
)

set(SOURCES
    qjsonrpcabstractserver.cpp
    qjsonrpchttpclient.cpp
    qjsonrpchttpserver.cpp
    qjsonrpclocalserver.cpp
    qjsonrpcmessage.cpp
    qjsonrpcservice.cpp
    qjsonrpcserviceprovider.cpp
    qjsonrpcservicereply.cpp
    qjsonrpcsocket.cpp
    qjsonrpctcpserver.cpp
)

set(PRIVATE_HEADERS
    qjsonrpcabstractserver_p.h
    qjsonrpchttpserver_p.h
    qjsonrpcservice_p.h
    qjsonrpcservicereply_p.h
    qjsonrpcsocket_p.h
)

add_qjsonrpc_library(qjsonrpc ${SOURCES} ${HEADERS} ${PRIVATE_HEADERS})
target_link_libraries(qjsonrpc PRIVATE Qt5::Core Qt5::Network Qt5::Gui)
target_link_libraries(qjsonrpc PRIVATE PkgConfig::HTTPParser)
target_include_directories(qjsonrpc PRIVATE "${QJSONRPC_INCLUDE_DIRS}")

install(FILES ${HEADERS} DESTINATION "${CMAKE_INSTALL_INCLUDEDIR}/qjsonrpc")

