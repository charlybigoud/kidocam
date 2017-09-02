#include "pinhole.hpp"

// Constructor
PinholeModel::PinholeModel(const double fu,
                           const double fv,
                           const double u0,
                           const double v0
                          )
: focal({fu,fv}), center({u0,v0})
{}

// Destructor
PinholeModel::~PinholeModel(){}

// Project a point according to the pinhole model
// p3d is expressed in the lens coordinate system
bool PinholeModel::project(const P3D& p3d, P2D& pixel) const
{
    pixel[0] = focal[0] * p3d[0] / p3d[2] + center[0];
    pixel[1] = focal[1] * p3d[1] / p3d[2] + center[1];

    return true;
}

{

    return true;
}

std::ostream& operator<<(std::ostream& os, const PinholeModel& pm)
{
    os << "focal (pixel): [" << pm.focal[0] << ", " << pm.focal[1] << "]\n";
    os << "center (pixel): [" << pm.center[0] << ", " << pm.center[1] << "]\n";

    return os;
}
