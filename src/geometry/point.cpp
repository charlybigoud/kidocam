#include "point.hpp"

std::ostream& operator<<(std::ostream& o, const P2D& p)
{
    o << "{" << p.x() << ", " << p.y() << "}";

    return o;
}

std::ostream& operator<<(std::ostream& o, const P3D& p)
{
    o << "{" << p.x() << ", " << p.y() << ", " << p.z() << "}";

    return o;
}
