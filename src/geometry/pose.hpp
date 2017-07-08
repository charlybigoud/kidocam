#pragma once

#include <geometry/point.hpp>

template<typename Type, int Dimension>
struct Pose
{
    // Point<Type,Dimension> translation;
    // // Matrix<Type,Dimension> rotation[Dimension][Dimension];

    // Ray(const Point<Type,Dimension>& o = Point<Type,Dimension>()
    //   , const Point<Type,Dimension>& d = Point<Type,Dimension>()
    // )
    // : origin(o), direction(d)
    // {}
};

using Pose2D = Pose<double,2>;
using Pose3D = Pose<double,3>;
