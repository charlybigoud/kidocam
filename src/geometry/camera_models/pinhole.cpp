#include "pinhole.hpp"

PinholeModel::PinholeModel(const double fu,
                           const double fv,
                           const double u0,
                           const double v0
                          )
: focal({fu,fv}), center({u0,v0})
{}

PinholeModel::~PinholeModel(){}

std::ostream& operator<<(std::ostream& os, const PinholeModel& pm)
{
    os << "focal (pixel): [" << pm.focal[0] << ", " << pm.focal[1] << "]\n";
    os << "center (pixel): [" << pm.center[0] << ", " << pm.center[1] << "]\n";

    return os;
}

/*
 * Project a point (expressed in the camera coordinate system)
*/
bool PinholeModel::project(const P3D& p3d, Ray3D& ray) const
{
    // ray =
    // (focal / k) * p3d[0] / p3d[2] + center[0]
    // ;

    return true;
}
