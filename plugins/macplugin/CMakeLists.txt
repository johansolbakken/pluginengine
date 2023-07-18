cmake_minimum_required(VERSION 3.15)

project(macplugin)

set(CMAKE_CXX_STANDARD 20)

add_library(macplugin SHARED
                macplugin.mm
                macplugin.h)
target_include_directories(macplugin PUBLIC src ../../engine/src)
target_link_libraries(macplugin PUBLIC engine "-framework Foundation")
