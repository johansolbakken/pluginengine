cmake_minimum_required(VERSION 3.15)

project(app)

set(CMAKE_CXX_STANDARD 20)

add_executable(app src/main.cpp)
target_link_libraries(app PRIVATE engine)
target_include_directories(app PRIVATE ../engine/src)
