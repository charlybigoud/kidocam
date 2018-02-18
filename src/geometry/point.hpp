#pragma once

#include <utils/types.hpp>

/*
 * 2d and 3d points
**/
using P2D = Eigen::Matrix<double, 2, 1>;
using P3D = Eigen::Matrix<double, 3, 1>;

using P2DS = AlignedVector<P2D>;
using P3DS = AlignedVector<P3D>;

/*
 * the custom operator<< for P2D
**/
std::ostream& operator<<(std::ostream& os, const P2D& p);

/*
 * the custom operator<< for P3D
**/
std::ostream& operator<<(std::ostream& os, const P3D& p);
