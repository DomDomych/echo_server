cmake_minimum_required(VERSION 3.16)

project(kv_server LANGUAGES CXX)

add_executable(kv_server
    main.cpp
    src/server/server.cpp
    src/session/session.cpp
)

target_include_directories(kv_server
    PRIVATE
    include
)

target_compile_features(kv_server
    PRIVATE
    cxx_std_20
)

target_compile_options(kv_server
    PRIVATE
    -Wall
    -Wextra
    -Wpedantic
)

add_executable(kv_client
    src/client/client.cpp
)

target_compile_features(kv_client
    PRIVATE
    cxx_std_20
)

target_compile_options(kv_client
    PRIVATE
    -Wall
    -Wextra
    -Wpedantic
)