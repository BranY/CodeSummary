cmake_minimum_required(VERSION 3.3)
project(hihoCoder)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES sol1038.cpp)
add_executable(hihoCoder ${SOURCE_FILES})