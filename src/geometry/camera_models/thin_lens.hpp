#pragma once

#include <iostream>

#include <Eigen/Dense>

struct ThinLensModel
{
    double focal; // The focal length (mm)
    double diameter; // Diameter of the lens (mm)


    ThinLensModel(const double f = 0.0,
                  const double d = 0.0
                 );

    ~ThinLensModel();

    template<int Dimension>
    bool project(const Eigen::Matrix<double, Dimension, 1>& p_in,
                       Eigen::Matrix<double, Dimension, 1>& p_out
                ) const;
};

std::ostream& operator<<(std::ostream& os, const ThinLensModel& tlm);

template<int Dimension>
bool ThinLensModel::project(const Eigen::Matrix<double, Dimension, 1>& p_in,
                                  Eigen::Matrix<double, Dimension, 1>& p_out
                          ) const
{
    //verifying if the point if well located
    if (p_in(Dimension - 1) == 0.0)
    {
        std::cerr << "Warning: ThinLensModel::project: The point is in the lens plane!" << std::endl;
        return false;
    }

    if (p_in(Dimension - 1) == focal)
    {
        std::cerr << "Warning: ThinLensModel::project: The point is in the focal plane!" << std::endl;
        return false;
    }

    //projecting the point
    const double value = -focal / (p_in(Dimension - 1) - focal);

    for (int i = 0; i < Dimension; ++i)
        p_out[i] =  value * p_in[i];

    return true;
}