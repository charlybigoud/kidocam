#include "thin_lens.hpp"

// Constructor
ThinLensModel::ThinLensModel(const double f)
: focal(f)
{}

// Destructor
ThinLensModel::~ThinLensModel(){}

// Project a point using the thin lens model
// p_in and p_out are expressed in the thin lens coordinate system
bool ThinLensModel::project(const P3D& p_in, P3D& p_out) const
{
    // Verifying if the point if well located
    if (p_in[2] == 0.0)
    {
        std::cerr << "Warning: ThinLensModel::project: "
                  << "The point is in the lens plane!"
                  << std::endl;

        return false;
    }

    if (p_in[2] == focal)
    {
        std::cerr << "Warning: ThinLensModel::project: "
                  << "The point is in the focal plane!"
                  << std::endl;

        return false;
    }

    // Projecting the point
    const double value = -focal / (p_in[2] - focal);

    for (int i = 0; i < 2; ++i)
        p_out[i] =  value * p_in[i];

    return true;
}

// Display inner property of a ThinLensModel
std::ostream& operator<<(std::ostream& os, const ThinLensModel& tlm)
{
    os << "focal (mm): " << tlm.focal << "\n";

    return os;
}
