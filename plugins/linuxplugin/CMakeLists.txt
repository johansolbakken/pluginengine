cmake_minimum_required(VERSION 3.15)

project(LinuxPlugin)

set(CMAKE_CXX_STANDARD 20)

add_library(linuxplugin SHARED
        linuxplugin.cpp
        linuxplugin.h)
target_include_directories(linuxplugin PUBLIC src ../../engine/src)
target_link_libraries(linuxplugin PUBLIC engine)
