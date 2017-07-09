#pragma once

#include <Eigen/Dense>

#include <utils/types.hpp>

template<typename Type, int Dimension>
struct Pose
{
    Eigen::Matrix<Type,Dimension,Dimension> rotation;
    Eigen::Matrix<Type,Dimension,1> translation;

    Pose(const Eigen::Matrix<Type,Dimension,Dimension>& r = Eigen::Matrix<Type,Dimension,Dimension>::Identity()
      , const Eigen::Matrix<Type,Dimension,1>& t = Eigen::Matrix<Type,Dimension,1>::Zero()
    )
    : rotation(r), translation(t)
    {}

    ~Pose(){};
};

using Pose2D = Pose<double,2>;
using Pose3D = Pose<double,3>;

using Poses2D = AlignedVector<Pose2D>;
using Poses3D = AlignedVector<Pose3D>;

template<typename Type, int Dimension>
std::ostream& operator<<(std::ostream& os, const Pose<Type,Dimension>& p)
{
    os << "rotation:\n" << p.rotation.transpose() << "\n";
    os << "translation: " << p.translation.transpose();

    return os;
}
