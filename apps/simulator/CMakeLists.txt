cmake_minimum_required(VERSION 2.8)

project(simulator)

add_executable(simulator src/main.cpp)

target_link_libraries(simulator kidocam)
