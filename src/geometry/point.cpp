#include "point.hpp"

#include <iostream>

/*
 * the custom operator<< for P2D
**/
std::ostream& operator<<(std::ostream& os, const P2D& p)
{
    os << "{" << p.x() << ", " << p.y() << "}";

    return os;
}

/*
 * the custom operator<< for P3D
**/
std::ostream& operator<<(std::ostream& os, const P3D& p)
{
    os << "{" << p.x() << ", " << p.y() << ", " << p.z() << "}";

    return os;
}
