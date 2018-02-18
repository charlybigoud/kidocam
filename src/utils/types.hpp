#pragma once

#include <Eigen/StdVector>

template<class Type>
using AlignedVector = std::vector<Type, Eigen::aligned_allocator<Type>>;
