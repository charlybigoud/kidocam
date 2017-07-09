cmake_minimum_required(VERSION 2.8)

project(simulator)

find_package(Eigen3 REQUIRED)

include_directories(${EIGEN3_INCLUDE_DIRS})

add_executable(simulator src/main.cpp)

target_link_libraries(simulator
kidocam
${EIGEN_LIBRAIRIES}
)
