#pragma once

#include <iostream>

#include <geometry/point.hpp>

struct ThinLensModel
{
    // The focal length (mm)
    double focal;

    // Constructor
    ThinLensModel(const double f = 0.0);

    // Destructor
    ~ThinLensModel();

    // Project a point using the thin lens model
    // p_in and p_out are expressed in the thin lens coordinate system
    bool project(const P3D& p_in, P3D& p_out) const;
};

// Display inner properties of a ThinLensModel
std::ostream& operator<<(std::ostream& os, const ThinLensModel& tlm);
