cmake_minimum_required(VERSION 3.15)

project(plugin1)

set(CMAKE_CXX_STANDARD 23)

add_library(plugin1 SHARED src/plugin1.cpp)
target_include_directories(plugin1 PUBLIC src ../../engine/src)