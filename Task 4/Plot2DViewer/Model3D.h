#pragma once
#include "Matrix.h"
#include "Point3D.h"

class Model3D
{
private:
	Matrix<double> vertices;
	Matrix<int> facets;

public:
	Model3D();
	Model3D(const Matrix<double>& vertices, const Matrix<int>& facets);

	const Matrix<double>& GetVertices() const;
	const Matrix<int>& GetFacets() const;
	Point3D<double> GetVertex(const int index) const;
	Model3D& Apply(const Matrix<double>& T);
};