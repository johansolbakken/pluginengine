cmake_minimum_required(VERSION 3.15)

project(engine)

set(CMAKE_CXX_STANDARD 20)

add_library(engine src/engine/engine.h src/engine/engine.cpp
    src/engine/plugin.h
    src/engine/pluginmanager.h src/engine/pluginmanager.cpp)
target_include_directories(engine PUBLIC src)
