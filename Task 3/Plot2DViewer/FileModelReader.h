#pragma once
#include <vector>
#include <istream>
#include "IModelReader.h"

class FileModelReader : public IModelReader
{
private:
	std::string filename;

	std::vector<std::string> ReadLines(std::istream& in);
	template<class T>
	std::vector<T> ReadVector(const std::string& line);
	Matrix<double> ReadVertexes(const std::vector<std::string>& lines);
	Matrix<int> ReadEdges(const std::vector<std::string>& lines);

public:
	FileModelReader(const std::string& filename);
	virtual ~FileModelReader();

	virtual Model2D Read2DModel();
};