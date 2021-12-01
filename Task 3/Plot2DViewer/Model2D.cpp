#include "Model2D.h"

Model2D::Model2D() : vertices(), edges(), comulative_at(Identity()), initial_vertices(vertices) 
{
	
}

Model2D::Model2D(const Matrix<double>& Vertices, const Matrix<int>& Edges) : vertices(Vertices), edges(Edges), comulative_at(Identity()), initial_vertices(Vertices)
{
    
}

Model2D::Model2D(const std::string& input_filename, const std::string& output_filename)
{

}

Matrix<double> Model2D::GetVertices()
{
	return vertices;
}

Matrix<int> Model2D::GetEdges()
{
	return edges;
}

double Model2D::GetVertexX(int p)
{
	return 0;
}

double Model2D::GetVertexY(int p)
{
	return 0;
}

void Model2D::Apply(const Matrix<double>& T)
{

}