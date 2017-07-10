cmake_minimum_required(VERSION 2.8)

#find_package(Eigen3 REQUIRED)
#include_directories(${EIGEN3_INCLUDE_DIR})

##fix for travis build##
pkg_search_module(Eigen3 REQUIRED eigen3)
include_directories(${EIGEN3_INCLUDE_DIR})
add_definitions(${EIGEN3_DEFINITIONS})

if(NOT EIGEN3_FOUND)
    # Fallback to cmake_modules
    find_package(cmake_modules REQUIRED)
    find_package(Eigen REQUIRED)
    set(EIGEN3_INCLUDE_DIRS ${EIGEN_INCLUDE_DIRS})
    set(EIGEN3_LIBRARIES ${EIGEN_LIBRARIES})  # Not strictly necessary as Eigen is head only
    # Possibly map additional variables to the EIGEN3_ prefix.
else()
    set(EIGEN3_INCLUDE_DIRS ${EIGEN3_INCLUDE_DIR})
endif()
##fix for travis build##

add_library(kidocam
    models/thin_lens.cpp
    models/kidoca.cpp
    geometry/mesh.cpp
    geometry/point.cpp
    geometry/pose.cpp
    geometry/ray.cpp
)

target_include_directories(kidocam PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}
${EIGEN_LIBRAIRIES}
)
