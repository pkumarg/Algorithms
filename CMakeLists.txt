cmake_minimum_required (VERSION 2.6)

project (Algorithm)

set(CMAKE_CXX_FLAGS "-g")

add_executable(algoTest "src/test/testMain.cpp")

target_include_directories(algoTest PRIVATE
    "src"
    "src/sort"
    "src/search"
    "src/string"
    "src/other"
    )
