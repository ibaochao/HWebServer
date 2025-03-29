cmake_minimum_required(VERSION 3.14)
project(HWebServer VERSION 1.0.1)
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED True)

find_library(mysqlclient Names mysqlclient REQUIRED)
find_library(pthread Names pthread REQUIRED)

set(SRC_DIR ${PROJECT_SOURCE_DIR}/src)
set(BIN_DIR ${PROJECT_SOURCE_DIR})
configure_file(
    ${SRC_DIR}/version.h.in 
    ${SRC_DIR}/version.h
)

add_executable(
    HWebServer
    ${SRC_DIR}/main.cpp
    ${SRC_DIR}/buffer/buffer.cpp
    ${SRC_DIR}/log/log.cpp
    ${SRC_DIR}/epoller/epoller.cpp
    ${SRC_DIR}/timer/heap_timer.cpp
    ${SRC_DIR}/pool/sqlconnpool.cpp
    ${SRC_DIR}/http/httprequest.cpp
    ${SRC_DIR}/http/httpresponse.cpp
    ${SRC_DIR}/http/httpconn.cpp
    ${SRC_DIR}/config/config.cpp
    ${SRC_DIR}/server/hwebserver.cpp
    ${SRC_DIR}/util/util.cpp
)
set_target_properties(HWebServer PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${BIN_DIR})
target_link_libraries(
    HWebServer
    pthread
    mysqlclient
)