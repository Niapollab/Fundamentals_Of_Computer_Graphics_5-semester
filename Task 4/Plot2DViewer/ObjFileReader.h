#pragma once
#include "IModel3DReader.h"

class ObjFileReader : public IModel3DReader
{
private:
	std::string filename;

	std::vector<std::string> ReadLines(std::istream& in);
	template<class T>
	std::vector<T> ReadVector(const std::string& line);
	Matrix<double> ReadVertexes(const std::vector<std::string>& lines);
	Matrix<int> ReadConnections(const std::vector<std::string>& lines);

public:
	ObjFileReader(const std::string& filename);
	virtual ~ObjFileReader();

	virtual Model3D Read3DModel();
};