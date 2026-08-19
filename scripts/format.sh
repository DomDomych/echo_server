#!usr/bin/env bash

find src include -type f \( -name "*.cpp" -o -name "*.hpp" \) -exec clang-format -i {} +
clang-format -i main.cpp