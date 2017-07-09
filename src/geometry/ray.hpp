#pragma once

#include <eigen3/Eigen/Dense>

#include <utils/types.hpp>

// template<typename Type, int Dimension>
// struct Ray
// {
//     Point<Type,Dimension> origin;
//     //I choosed to set dimension type as a Point...
//     //fundamentaly this is not a point but anyway
//     Point<Type,Dimension> direction;

//     Ray(const Point<Type,Dimension>& o = Point<Type,Dimension>()
//       , const Point<Type,Dimension>& d = Point<Type,Dimension>()
//     )
//     : origin(o), direction(d)
//     {}
// };

// using Ray2D = Ray<double,2>;
// using Ray3D = Ray<double,3>;

// using Rays2D = std::vector<Ray2D>;
// using Rays3D = std::vector<Ray3D>;

// template<typename Type, int Dimension>
// std::ostream& operator<<(std::ostream& o, const Ray<Type,Dimension>& r)
// {
//     o << "origin: " << r.origin << "\n";
//     o << "direction: " << r.direction;

//     return o;
// }


template<typename Type, int Dimension>
struct Ray
{
    Eigen::Matrix<Type,Dimension,1> origin;
    Eigen::Matrix<Type,Dimension,1> direction;

    Ray(const Eigen::Matrix<Type,Dimension,1>& o = Eigen::Matrix<Type,Dimension,1>::Zero()
      , const Eigen::Matrix<Type,Dimension,1>& d = Eigen::Matrix<Type,Dimension,1>::Zero()
    )
    : origin(o), direction(d)
    {}
};

using Ray2D = Ray<double,2>;
using Ray3D = Ray<double,3>;

using Rays2D = AlignedVector<Ray2D>;
using Rays3D = AlignedVector<Ray3D>;

template<typename Type, int Dimension>
std::ostream& operator<<(std::ostream& o, const Ray<Type,Dimension>& r)
{
    o << "origin: " << r.origin << "\n";
    o << "direction: " << r.direction;

    return o;
}
