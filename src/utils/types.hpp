#pragma once

#include <vector>

#include <Eigen/Core>
#include <Eigen/StdVector>

template<class T> using AlignedVector = std::vector<T,Eigen::aligned_allocator<T>>;
