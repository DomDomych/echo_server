cmake_minimum_required(VERSION 3.16)

project(echo_server LANGUAGES CXX)

add_executable(echo_server
    main.cpp
    src/server/server.cpp
    src/session/session.cpp
)

target_include_directories(echo_server
    PRIVATE
    include
)