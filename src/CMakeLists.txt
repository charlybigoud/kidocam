cmake_minimum_required(VERSION 2.8)

set(CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR})

find_package(Eigen3 REQUIRED)

add_library(kidocam
    models/thin_lens.cpp
    models/kidoca.cpp
    geometry/point.cpp
    geometry/ray.cpp
)

include_directories(${EIGEN3_INCLUDE_DIR})

target_include_directories(kidocam PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}
${EIGEN_LIBRAIRIES}
)
