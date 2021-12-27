#pragma once
#include <string>
#include <fstream>
#include "Matrix.h"
#include "AffineTransform.h"

class Model2D
{
private:
	Matrix<double> vertices;
	Matrix<int> edges;

public:
	Model2D();
	Model2D(const Matrix<double>& vertices, const Matrix<int>& edges);

	const Matrix<double>& GetVertices() const;
	const Matrix<int>& GetEdges() const;
	std::pair<double, double> GetVertex(const int index) const;
	Model2D& Apply(const Matrix<double>& T);
};