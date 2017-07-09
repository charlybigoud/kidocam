cmake_minimum_required(VERSION 2.8)

find_package(Eigen3 REQUIRED)

include_directories(${EIGEN3_INCLUDE_DIR})

add_library(kidocam
    models/thin_lens.cpp
    models/kidoca.cpp
    geometry/point.cpp
    geometry/pose.cpp
    geometry/ray.cpp
)

target_include_directories(kidocam PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}
${EIGEN_LIBRAIRIES}
)
