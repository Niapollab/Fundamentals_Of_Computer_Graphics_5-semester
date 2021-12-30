#include "Model2D.h"

Model2D::Model2D() : vertices(), edges() 
{
	
}

Model2D::Model2D(const Matrix<double>& vertices, const Matrix<int>& edges) : vertices(vertices), edges(edges)
{
    
}

const Matrix<double>& Model2D::GetVertices() const
{
	return vertices;
}

const Matrix<int>& Model2D::GetEdges() const
{
	return edges;
}

Point2D<double> Model2D::GetVertex(const int index) const
{
	const double p = vertices[2][index];
	return { vertices[0][index] / p, vertices[1][index] / p };
}

Model2D& Model2D::Apply(const Matrix<double>& T)
{
	vertices = T * vertices;
	return *this;
}