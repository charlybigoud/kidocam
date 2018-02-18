#pragma once

#include <Eigen/Dense>

#include <utils/types.hpp>

template<int Dimension>
struct Ray
{
    Eigen::Matrix<double, Dimension, 1> origin;
    Eigen::Matrix<double, Dimension, 1> direction;

    /*
     * Ray constructor
    **/
    Ray(const Eigen::Matrix<double, Dimension, 1>& o = Eigen::Matrix<double, Dimension, 1>::Zero(),
        const Eigen::Matrix<double, Dimension, 1>& d = Eigen::Matrix<double, Dimension, 1>::Zero())
    : origin(o), direction(d)
    {}

    /*
     * Ray destructor
    **/
    ~Ray(){};
};

using Ray2D = Ray<2>;
using Ray3D = Ray<3>;

using Rays2D = AlignedVector<Ray2D>;
using Rays3D = AlignedVector<Ray3D>;

/*
 * the custom operator<< for Ray
**/
template<int Dimension>
std::ostream& operator<<(std::ostream& os, const Ray<Dimension>& r)
{
    os << "origin: " << r.origin << "\n";
    os << "direction: " << r.direction;

    return os;
}
