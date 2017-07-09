#include "mesh.hpp"

std::ostream& operator<<(std::ostream& os, const Geometry& g)
{
    if (g == 0)
        os << "Triangular";
    else if (g == 1)
        os << "Orthogonal";
    else if (g == 2)
        os << "Hexagonal";
    else
        os << "ERR_GEOMETRY_UNDEFINED";

    return os;
}

std::ostream& operator<<(std::ostream& os, const Orientation& o)
{
    if (o == 0)
        os << "Horizontal";
    else if (o == 1)
        os << "Vertical";
    else
        os << "ERR_ORIENTATION_UNDEFINED";

    return os;
}
