#include <iostream>

#include <models/kidoca.hpp>

int main()
{
    Kidoca kidoca;

    P3D p3d;
    P2D p2d;

    kidoca.project(p3d, p2d);

    Ray3D ray;

    kidoca.raytrace(p2d, ray);

    return 0;
}
