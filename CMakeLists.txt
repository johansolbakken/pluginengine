cmake_minimum_required(VERSION 3.15)

project("PluginEngine")

if (UNIX AND NOT APPLE)
    set(CMAKE_POSITION_INDEPENDENT_CODE ON)
endif()

add_subdirectory(app)
add_subdirectory(engine)
add_subdirectory(plugins)
