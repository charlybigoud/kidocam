#pragma once

#include <iostream>

#include <Eigen/Dense>

//The geometry of the grid
enum Geometry
{
    Triangular = 0,
    Orthogonal = 1,
    Hexagonal = 2
};

std::ostream& operator<<(std::ostream& os, const Geometry& g);

//The orientation of the grid
enum Orientation
{
    Horizontal = 0,
    Vertical = 1
};

std::ostream& operator<<(std::ostream& os, const Orientation& o);

//this is a flat mesh
//i will principaly use it to set lens array and checkerboard (if needed ;) )
template<int Dimension>
struct PolygonMesh
{
    Geometry geometry;
    Orientation orientation;
    std::array<int,2> dimensions;
    double edge_length;  //the mean distance between two vertices

    PolygonMesh(const Geometry g = Triangular
              , const Orientation o = Horizontal
              , const std::array<int,2>& d = std::array<int,2>{0,0}
              , const double e = 0.0
        )
    : geometry(g), dimensions(d), edge_length(e)
    {}

    ~PolygonMesh(){};

    Eigen::Matrix<double,Dimension,1> vertex(const int col, const int row) const;
    // Eigen::Matrix<double,Dimension,1> vertex(const int i) const;

    // return edge parameters linking two nodes (note by indices)
    // edge(const int i1, const int i2) const;
};

using PolygonMesh2D = PolygonMesh<2>;
using PolygonMesh3D = PolygonMesh<3>;

template<int Dimension>
Eigen::Matrix<double,Dimension,1> PolygonMesh<Dimension>::vertex(const int col, const int row) const
{
    // if ( col < 0 or col >= width )
    //     throw(std::out_of_range( boost::str(boost::format("PolygonMesh<Dimension>::vertex: wrong col index (%1%)")%col)) );
    // if ( row < 0 or row >= height )
    //     throw(std::out_of_range( boost::str(boost::format("PolygonMesh<Dimension>::vertex: wrong row index (%1%)")%row)) );

    Eigen::Matrix<double,Dimension,1> p = Eigen::Matrix<double,Dimension,1>::Zero();

    if (geometry == Triangular)
    {
        std::cerr << "Error: PolygonMesh::vertex: Not implemented." << std::endl;
        if (orientation == Horizontal)
        {
            return p;
        }
        else if (orientation == Vertical)
        {
            return p;
        }
        else
            std::cerr << "Error: PolygonMesh::vertex: wrong orientation value (" << orientation << ")."<< std::endl;

    }
    else if (geometry == Orthogonal)
    {
        p.x() = edge_length * (double(col) + double(row));
        p.y() = edge_length * (double(row) + double(col));
    }
    else if (geometry == Hexagonal)
    {
        double val = 0.0;
        if (orientation == Horizontal)
        {
            if (row%2 == 0)
                val = 0.5;

            p.x() =  (double(col) + val) * edge_length;
            p.y() =  double(row) * edge_length * std::sin(M_PI / 3.0);

            return p;

        }
        if (orientation == Vertical)
        {
            if (col%2 == 0)
                val = 0.5;

            p.x() = double(col) * edge_length * std::sin(M_PI / 3.0);
            p.y() = (double(row) + val) * edge_length;

            return p;
        }
        else
            std::cerr << "Error: PolygonMesh::vertex: wrong orientation value (" << orientation << ")."<< std::endl;
    }    
    else
        std::cerr << "Error: PolygonMesh::vertex: wrong geometry value (" << geometry << ")."<< std::endl;

    return {};
}

template<int Dimension>
std::ostream& operator<<(std::ostream& os, const PolygonMesh<Dimension>& m)
{
    os << "geometry: " << m.geometry << "\n";
    os << "orientation: " << m.orientation << "\n";
    os << "dimensions: [" << m.dimensions[0] << ", " << m.dimensions[1] << "]\n"; 
    os << "edges length: " << m.edge_length;

    return os;
}
