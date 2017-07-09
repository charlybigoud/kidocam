#include "thin_lens.hpp"
#include "thin_lens.hpp"

std::ostream& operator<<(std::ostream& os, const ThinLensModel& tlm)
{
    os << "focal (mm): " << tlm.focal << "\n";
    os << "diameter (mm): " << tlm.diameter << "\n";

    return os;
}
