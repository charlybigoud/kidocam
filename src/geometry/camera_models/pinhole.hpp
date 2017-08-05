#pragma once

#include <iostream>

#include <geometry/point.hpp>
#include <geometry/ray.hpp>

struct PinholeModel{
    std::array<double,2> focal; // The focal length (mm)
    std::array<double,2> center; // The focal length (mm)

    PinholeModel(const double fu = 0.0,
                 const double fv = 0.0,
                 const double u0 = 0.0,
                 const double v0 = 0.0
                );

    ~PinholeModel();

    bool project(const P3D& p3d, Ray3D& ray) const;

    // bool raytrace();
};

std::ostream& operator<<(std::ostream& os, const PinholeModel& pm);
