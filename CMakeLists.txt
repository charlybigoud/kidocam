cmake_minimum_required(VERSION 2.8)

project(kidocam)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} ${PROJECT_SOURCE_DIR}/cmake)

add_definitions(-std=c++1y -O3)

add_subdirectory(src)

#add_subdirectory(third_party/pangolin)

add_subdirectory(apps/simulator)
