#pragma once

#include <geometry/point.hpp>

template<typename Type, int Dimension>
struct Ray
{
    Point<Type,Dimension> origin;
    //I choosed to set dimension type as a Point...
    //fundamentaly this is not a point but anyway
    Point<Type,Dimension> direction;

    Ray(const Point<Type,Dimension>& o = Point<Type,Dimension>()
      , const Point<Type,Dimension>& d = Point<Type,Dimension>()
    )
    : origin(o), direction(d)
    {}
};

using Ray2D = Ray<double,2>;
using Ray3D = Ray<double,3>;

using Rays2D = std::vector<Ray2D>;
using Rays3D = std::vector<Ray3D>;

template<typename Type, int Dimension>
std::ostream& operator<<(std::ostream& o, const Ray<Type,Dimension>& r)
{
    o << "origin: " << r.origin << "\n";
    o << "direction: " << r.direction;

    return o;
}
