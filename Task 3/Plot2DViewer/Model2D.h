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
	Matrix<double> comulative_at;
	Matrix<double> initial_vertices;

public:
	Model2D();
	Model2D(const Matrix<double>& Vertices, const Matrix<int>& Edges);
	Model2D(const std::string& input_filename, const std::string& output_filename);

	Matrix<double> GetVertices();
	Matrix<int> GetEdges();
	double GetVertexX(int p);
	double GetVertexY(int p);
	void Apply(const Matrix<double>& T);
};