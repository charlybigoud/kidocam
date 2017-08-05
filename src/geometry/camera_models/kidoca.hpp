#pragma once

#include <geometry/point.hpp>
#include <geometry/ray.hpp>

struct Kidoca
{
    bool project(const P3D& p3d, P2D& pixel) const;
    bool raytrace(const P2D& pixel, Ray3D& ray) const;
};
