#include "Model3D.h"

Model3D::Model3D() : vertices(), facets()
{
}

Model3D::Model3D(const Matrix<double>& vertices, const Matrix<int>& facets) : vertices(vertices), facets(facets)
{
}

const Matrix<double>& Model3D::GetVertices() const
{
	return vertices;
}

const Matrix<int>& Model3D::GetFacets() const
{
	return facets;
}

Point3D<double> Model3D::GetVertex(const int index) const
{
	const double p = vertices[3][index];
	return { vertices[0][index] / p, vertices[1][index] / p,  vertices[2][index] / p };
}

Model3D& Model3D::Apply(const Matrix<double>& T)
{
	vertices = T * vertices;
	return *this;
}