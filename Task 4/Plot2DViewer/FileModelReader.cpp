#include <fstream>
#include <sstream>
#include "FileModelReader.h"

FileModelReader::FileModelReader(const std::string& filename) : filename(filename)
{
}

FileModelReader::~FileModelReader()
{
}

Model2D FileModelReader::Read2DModel()
{
    std::ifstream file(filename);
    if (file)
    {
        const size_t VERTEX_ROWS_COUNT = 3;

        std::vector<std::string> lines = ReadLines(file);
        file.close();

        Matrix<double> vertexes = ReadVertexes(lines, VERTEX_ROWS_COUNT);
        if (vertexes.get_rows_size() < 1)
            return Model2D();

        Matrix<int> edges = ReadConnections(lines, VERTEX_ROWS_COUNT);
        if (edges.get_rows_size() < 1)
            return Model2D();
        
        return Model2D(vertexes, edges);
    }

    return Model2D();
}

Model3D FileModelReader::Read3DModel()
{
    std::ifstream file(filename);
    if (file)
    {
        const size_t VERTEX_ROWS_COUNT = 4;

        std::vector<std::string> lines = ReadLines(file);
        file.close();

        Matrix<double> vertexes = ReadVertexes(lines, VERTEX_ROWS_COUNT);
        if (vertexes.get_rows_size() < 1)
            return Model3D();

        Matrix<int> facets = ReadConnections(lines, VERTEX_ROWS_COUNT);
        if (facets.get_rows_size() < 1)
            return Model3D();

        return Model3D(vertexes, facets);
    }

    return Model3D();
}

std::vector<std::string> FileModelReader::ReadLines(std::istream& in)
{
    std::vector<std::string> lines;

    std::string line;
    while (std::getline(in, line))
        lines.push_back(line);

    return lines;
}

template<class T>
std::vector<T> FileModelReader::ReadVector(const std::string& line)
{
    std::vector<T> result;
    std::istringstream line_reader(line);

    T obj = T();
    while (line_reader >> obj)
        result.push_back(obj);

    return result;
}

template<class T>
bool HasSameLength(const std::vector<std::vector<T>>& vec)
{
    if (vec.size() < 1)
        return true;

    size_t size = vec[0].size();
    for (size_t i = 1; i < vec.size(); ++i)
        if (vec[i].size() != size)
            return false;

    return true;
}

Matrix<double> FileModelReader::ReadVertexes(const std::vector<std::string>& lines, size_t vertex_rows_count)
{
    if (lines.size() < vertex_rows_count)
        return Matrix<double>();

    std::vector<std::vector<double>> rows(vertex_rows_count);
    for (size_t i = 0; i < rows.size(); ++i)
        rows[i] = ReadVector<double>(lines[i]);

    if (!HasSameLength(rows))
        return Matrix<double>();

    Matrix<double> matrix(rows.size(), rows[0].size());
    for (size_t i = 0; i < matrix.get_rows_size(); ++i)
        for (size_t j = 0; j < matrix.get_columns_size(); ++j)
            matrix[i][j] = rows[i][j];

    return matrix;
}

Matrix<int> FileModelReader::ReadConnections(const std::vector<std::string>& lines, size_t vertex_rows_count)
{
    if (lines.size() <= vertex_rows_count)
        return Matrix<int>();
    
    std::vector<std::vector<int>> rows;
    for (size_t i = vertex_rows_count; i < lines.size(); ++i)
        rows.push_back(ReadVector<int>(lines[i]));

    if (!HasSameLength(rows))
        return Matrix<int>();

    Matrix<int> matrix(rows.size(), rows[0].size());
    for (size_t i = 0; i < matrix.get_rows_size(); ++i)
        for (size_t j = 0; j < matrix.get_columns_size(); ++j)
            matrix[i][j] = rows[i][j];

    return matrix;
}