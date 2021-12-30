#pragma once
#include <vector>
#include <istream>
#include "IModel2DReader.h"
#include "IModel3DReader.h"

class FileModelReader : public IModel2DReader, public IModel3DReader
{
private:
	std::string filename;

	std::vector<std::string> ReadLines(std::istream& in);
	template<class T>
	std::vector<T> ReadVector(const std::string& line);
	Matrix<double> ReadVertexes(const std::vector<std::string>& lines, size_t vertex_rows_count);
	Matrix<int> ReadConnections(const std::vector<std::string>& lines, size_t vertex_rows_count);

public:
	FileModelReader(const std::string& filename);
	virtual ~FileModelReader();

	virtual Model2D Read2DModel();
	virtual Model3D Read3DModel();
};