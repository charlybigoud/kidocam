#include <iostream>

#include <geometry/mesh.hpp>
#include <geometry/pose.hpp>
#include <geometry/camera_models/thin_lens.hpp>
#include <geometry/camera_models/pinhole.hpp>
#include <geometry/camera_models/kidoca.hpp>

int main()
{
    P3D p3d(0.0,0.0,0.0);
    std::cout << "p3d: " << p3d << std::endl;
    P2D p2d(0.0,0.0);
    std::cout << "p2d: " << p2d << std::endl;

    Ray3D ray3d(P3D(1.0,0.0,0.0), P3D(1.0,0.0,122.45));
    std::cout << "ray3d:\n" << ray3d << std::endl;

    Ray2D ray2d(P2D(1.0,0.0), P2D(1.0,122.45));
    std::cout << "ray2d:\n" << ray2d << std::endl;

    Pose2D pose2d;
    std::cout << "pose2d:\n" << pose2d << std::endl;

    Pose3D pose3d;
    std::cout << "pose3d:\n" << pose3d << std::endl;

    Kidoca kidoca;
    kidoca.raytrace(p2d, ray3d);
    kidoca.project(p3d, p2d);

    PolygonMesh2D mesh2d(Orthogonal);
    std::cout << "mesh2d:\n" << mesh2d << std::endl;

    PolygonMesh3D mesh3d;
    std::cout << "mesh3d:\n" << mesh3d << std::endl;

    ThinLensModel tlm(10.);
    std::cout << "tlm:\n" << tlm << std::endl;

    p3d = {20.0, 20.0, 20.0};
    tlm.project(p3d, p3d);
    std::cout << "p3d:\n" << p3d << std::endl;

    p2d = {2000.0, 54118814.0};
    tlm.project(p2d, p2d);
    std::cout << "p2d:\n" << p2d << std::endl;

    PinholeModel pm(100.0, 100.0, 400.0, 300.0);
    std::cout << "pm: " << pm << std::endl;

    pm.project(p3d, ray3d);
    std::cout << "ray3d:\n" << ray3d << std::endl;

    return 0;
}
