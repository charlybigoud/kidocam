#include <iostream>

#include <geometry/pose.hpp>
#include <models/kidoca.hpp>

int main()
{
    Kidoca kidoca;

    P3D p3d(0.0,0.0,0.0);
    std::cout << "p3d: " << p3d << std::endl;
    P2D p2d(0.0,0.0);
    std::cout << "p2d: " << p2d << std::endl;

    kidoca.project(p3d, p2d);

    Ray3D ray3d(P3D(1.0,0.0,0.0), P3D(1.0,0.0,122.45));
    std::cout << "ray3d:\n" << ray3d << std::endl;

    Ray2D ray2d(P2D(1.0,0.0), P2D(1.0,122.45));
    std::cout << "ray2d:\n" << ray2d << std::endl;

    kidoca.raytrace(p2d, ray3d);

    return 0;
}
