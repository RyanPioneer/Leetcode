cmake_minimum_required(VERSION 3.26)
project(0501_1000)

set(CMAKE_CXX_STANDARD 20)

include_directories(.)

add_executable(0501_1000
        test.cpp
        "0924. Minimize Malware Spread/main.cpp")
