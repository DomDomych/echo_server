cmake_minimum_required(VERSION 3.16)

project(kv_server LANGUAGES CXX)

add_executable(kv_server
    main.cpp
    src/server/server.cpp
    src/session/session.cpp
    src/protocol/parser.cpp
    src/protocol/command_processor.cpp
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

find_package(GTest REQUIRED)

add_executable(kv_tests
    tests/parser_tests.cpp
    
    src/protocol/parser.cpp
)

target_link_libraries(kv_tests
    PRIVATE
    GTest::gtest_main
)

target_include_directories(kv_tests
    PRIVATE
    include)

target_compile_features(kv_tests
    PRIVATE
    cxx_std_20
)

target_compile_options(kv_tests
    PRIVATE
    -Wall
    -Wextra
    -Wpedantic
)