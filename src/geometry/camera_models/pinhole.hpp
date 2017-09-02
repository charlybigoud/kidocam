#pragma once

#include <iostream>

#include <geometry/point.hpp>
#include <geometry/ray.hpp>

struct PinholeModel{
    std::array<double,2> focal; // The focal length (mm)
    std::array<double,2> center; // The focal length (mm)

    // Constructor
    PinholeModel(const double fu = 0.0,
                 const double fv = 0.0,
                 const double u0 = 0.0,
                 const double v0 = 0.0
                );

    // Destructor
    ~PinholeModel();

    bool project(const P3D& p3d, P2D& pixel) const;

    bool raytrace(const P2D& pixel, Ray3D& ray) const;

};

std::ostream& operator<<(std::ostream& os, const PinholeModel& pm);
