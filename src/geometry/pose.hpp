#pragma once

#include <Eigen/Dense>

#include <utils/types.hpp>

template<int Dimension>
struct Pose
{
    Eigen::Matrix<double, Dimension, Dimension> rotation;
    Eigen::Matrix<double, Dimension, 1> translation;

    Pose(const Eigen::Matrix<double, Dimension, Dimension>& r = Eigen::Matrix<double, Dimension, Dimension>::Identity()
       , const Eigen::Matrix<double, Dimension, 1>& t = Eigen::Matrix<double, Dimension,1>::Zero()
    )
    : rotation(r), translation(t)
    {}

    ~Pose(){};
};

using Pose2D = Pose<2>;
using Pose3D = Pose<3>;

using Poses2D = AlignedVector<Pose2D>;
using Poses3D = AlignedVector<Pose3D>;

template<int Dimension>
std::ostream& operator<<(std::ostream& os, const Pose<Dimension>& p)
{
    os << "rotation:\n" << p.rotation.transpose() << "\n";
    os << "translation: " << p.translation.transpose();

    return os;
}
