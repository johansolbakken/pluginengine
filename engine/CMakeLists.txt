cmake_minimum_required(VERSION 3.15)

project(engine)

set(CMAKE_CXX_STANDARD 23)

add_library(engine src/engine/engine.h src/engine/engine.cpp)
target_include_directories(engine PUBLIC src)