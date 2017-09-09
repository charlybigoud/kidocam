cmake_minimum_required(VERSION 2.8)

find_package(Eigen3 REQUIRED)

include_directories(${EIGEN3_INCLUDE_DIR})

add_library(kitchen_door
    geometry/camera_models/pinhole.cpp
    geometry/camera_models/thin_lens.cpp
    geometry/camera_models/kitchen_door.cpp
    geometry/mesh.cpp
    geometry/point.cpp
    geometry/pose.cpp
    geometry/ray.cpp
)

target_include_directories(kitchen_door PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}
${EIGEN_LIBRAIRIES}
)
