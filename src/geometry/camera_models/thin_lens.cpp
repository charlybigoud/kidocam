#include "thin_lens.hpp"

ThinLensModel::ThinLensModel(const double f)
: focal(f)
{}

ThinLensModel::~ThinLensModel(){}

std::ostream& operator<<(std::ostream& os, const ThinLensModel& tlm)
{
    os << "focal (mm): " << tlm.focal << "\n";

    return os;
}
