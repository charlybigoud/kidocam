#include "point.hpp"

std::ostream& operator<<(std::ostream& os, const P2D& p)
{
    os << "{" << p.x() << ", " << p.y() << "}";

    return os;
}

std::ostream& operator<<(std::ostream& os, const P3D& p)
{
    os << "{" << p.x() << ", " << p.y() << ", " << p.z() << "}";

    return os;
}
