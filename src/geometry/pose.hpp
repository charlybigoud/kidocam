#pragma once

template<typename Type, int Dimension>
struct Pose
{
    Type translation[Dimension];
    Type rotation[Dimension][Dimension];
};

using Pose2D = Pose<double,2>;
using Pose3D = Pose<double,3>;
