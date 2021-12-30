#include <fstream>
#include <sstream>
#include "ObjFileReader.h"

ObjFileReader::ObjFileReader(const std::string& filename) : filename(filename)
{
}

ObjFileReader::~ObjFileReader()
{
}

Model3D ObjFileReader::Read3DModel()
{
    std::ifstream file(filename);
    if (file)
    {
        const std::string VERTEX_PATTERN = "v ";
        const std::string FACET_PATTERN = "f ";
        const size_t VERTEX_ROWS_COUNT = 4;

        std::vector<std::string> lines = ReadLines(file);
        file.close();

        std::vector<std::string> vertexies_row;
        std::vector<std::string> facets_row;
        for (const auto& line : lines)
        {
            if (line.find(VERTEX_PATTERN) == 0)
            {
                std::string temp(line);

                temp.erase(0, VERTEX_PATTERN.size());

                vertexies_row.push_back(temp);
            }
            else if (line.find(FACET_PATTERN) == 0)
            {
                std::string temp(line);

                temp.erase(0, FACET_PATTERN.size());

                facets_row.push_back(temp);
            }
        }

        Matrix<double> vertexes = ReadVertexes(vertexies_row);
        if (vertexes.get_rows_size() < 1)
            return Model3D();

        Matrix<int> facets = ReadConnections(facets_row);
        if (facets.get_rows_size() < 1)
            return Model3D();

        for (size_t i = 0; i < facets.get_rows_size(); ++i)
        {
            for (size_t j = 0; j < facets.get_columns_size(); ++j)
            {
                auto z = facets[i][j];
                auto g = 0;
            }
        }

        return Model3D(vertexes, facets);
    }

    return Model3D();
}

std::vector<std::string> ObjFileReader::ReadLines(std::istream& in)
{
    std::vector<std::string> lines;

    std::string line;
    while (std::getline(in, line))
        lines.push_back(line);

    return lines;
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

Matrix<double> ObjFileReader::ReadVertexes(const std::vector<std::string>& lines)
{
    std::vector<std::vector<double>> rows;
    for (size_t i = 0; i < lines.size(); ++i)
    {
        std::vector<double> temp = ReadVector<double>(lines[i]);
        temp.push_back(1);

        rows.push_back(temp);
    }

    if (!HasSameLength(rows))
        return Matrix<double>();

    Matrix<double> matrix(rows.size(), rows[0].size());
    for (size_t i = 0; i < matrix.get_rows_size(); ++i)
        for (size_t j = 0; j < matrix.get_columns_size(); ++j)
            matrix[i][j] = rows[i][j];

    return matrix.transpose();
}

Matrix<int> ObjFileReader::ReadConnections(const std::vector<std::string>& lines)
{
    std::vector<std::vector<int>> rows;
    for (size_t i = 0; i < lines.size(); ++i)
    {
        std::vector<int> temp = ReadVector<int>(lines[i]);
        for (auto& element : temp)
            --element;

        rows.push_back(temp);
    }

    if (!HasSameLength(rows))
        return Matrix<int>();

    Matrix<int> matrix(rows.size(), rows[0].size());
    for (size_t i = 0; i < matrix.get_rows_size(); ++i)
        for (size_t j = 0; j < matrix.get_columns_size(); ++j)
            matrix[i][j] = rows[i][j];

    return matrix;
}

template<class T>
std::vector<T> ObjFileReader::ReadVector(const std::string& line)
{
    std::vector<T> result;
    std::istringstream line_reader(line);

    T obj = T();
    while (line_reader >> obj)
        result.push_back(obj);

    return result;
}