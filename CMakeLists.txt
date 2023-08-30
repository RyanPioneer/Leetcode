cmake_minimum_required(VERSION 3.26)
project(Leetcode)

set(CMAKE_CXX_STANDARD 20)

include_directories(.)
include_directories(0001~0500)
include_directories(0501~1000)
include_directories(1001~1500)
include_directories(1501~2000)
include_directories(2001~2500)
include_directories(2501~3000)
include_directories(Template)

add_executable(Leetcode
        "2001~2500/2366. Minimum Replacements to Sort the Array/main.cpp")
