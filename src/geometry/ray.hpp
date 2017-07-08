#pragma once

#include <vector>

template<typename Type, int Dimension>
struct Ray
{

};

using Ray2D = Ray<double,2>;
using Ray3D = Ray<double,3>;

using Rays2D = std::vector<Ray2D>;
using Rays3D = std::vector<Ray3D>;
