#pragma once

#include <vector>

#include <eigen3/Eigen/Core>
#include <eigen3/Eigen/StdVector>

template<class T> using AlignedVector = std::vector<T,Eigen::aligned_allocator<T>>;
