#pragma once

#include <iostream>
#include <vector>

#include <Eigen/Dense>

#include <utils/types.hpp>

// template<typename Type, int Dimension>
// struct Point
// {
//     Type data[Dimension];

//     template<typename ... X>
//     Point(X ... t)
//     : data{ Type(t)... }
//     {}

//     ~Point(){}

//     template<int I>
//     Type& at()
//     {
//         static_assert(Dimension > I,"Error: Point::at() out of range.");
//         return data[I];
//     }

//     template<int I>
//     const Type& at() const
//     {
//         static_assert(Dimension > I,"Error: Point::at() out of range.");
//         return data[I];
//     }

//     Type& x() { return at<0>(); }
//     Type& y() { return at<1>(); }
//     Type& z() { return at<2>(); }

//     const Type& x() const { return at<0>(); }
//     const Type& y() const { return at<1>(); }
//     const Type& z() const { return at<2>(); }

//     Type norm() const
//     {
//         return spec_norm(*this);
//     }
// };

// using P2D = Point<double, 2>;
// using P3D = Point<double, 3>;


//eigen dependent type
using P2D = Eigen::Matrix<double, 2, 1>;
using P3D = Eigen::Matrix<double, 3, 1>;

using P2DS = AlignedVector<P2D>;
using P3DS = AlignedVector<P3D>;

std::ostream& operator<<(std::ostream& o, const P2D& p);
std::ostream& operator<<(std::ostream& o, const P3D& p);
