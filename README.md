Fork
====

This is a fork of the original QJsonRpc library which you can get at: 
[qjsonrpc](https://bitbucket.org/devonit/qjsonrpc).


- Fork introduces use of cmake build system instead of qmake. 
- It also fixes issue with broken qjsonrpcserver auto-test when building against Qt 5.15.
- Fork provides CI/CD via github actions.
- Additionally ability to build RPM packages for ALT linux distribution has been implemented.

Overview
=======

QJsonRpc is a Qt implementation of the JSON-RPC protocol.
It integrates nicely with Qt, leveraging Qt's meta object system in order
to provide services over the JSON-RPC protocol. QJsonRpc is licensed under
the LGPLv2.1.

- [JSON](http://www.json.org/) is a lightweight data interchange format.
- [JSON-RPC](http://jsonrpc.org/) is lightweight remote procedure call protocol similar to XML-RPC.

Help / Questions / Suggestions
============
[qjsonrpc-development](http://groups.google.com/group/qjsonrpc-development)

Requirements
============

- Qt 5.15 or greater

Features
========

- Support for JSON-RPC 2.0
- Easily create services using the Qt meta object system
- QtScript integration

Building
========

    mkdir build
    cd build
    cmake .. && make install

You can pass the following arguments to cmake:

    -DQJSONRPC_BUILD_TESTS=BOOL:ON    to enable cmake build tests
                                      default:
                                          OFF
