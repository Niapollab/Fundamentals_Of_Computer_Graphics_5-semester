#pragma once
#include <initializer_list>
#include <stdexcept>
#include "MatrixRow.h"

template<class T>
class Matrix
{
private:
	size_t rows_size;
	size_t columns_size;
	MatrixRow<T>* raw_matrix;

	static bool all_initializer_list_sizes_equals(const std::initializer_list<const std::initializer_list<const T>>& list) noexcept;

public:
	Matrix() noexcept;
	Matrix(const std::initializer_list<const std::initializer_list<const T>>& list);
	Matrix(const size_t rows_size, const size_t columns_size);
	Matrix(const Matrix& matrix) noexcept;
	Matrix(Matrix&& matrix) noexcept;
	~Matrix() noexcept;

	size_t get_rows_size() const;
	size_t get_columns_size() const;
	Matrix transpose() const noexcept;
	Matrix& operator=(const Matrix& matrix) noexcept;
	Matrix& operator=(Matrix&& matrix) noexcept;
	Matrix operator+(const Matrix& matrix) const;
	Matrix operator-(const Matrix& matrix) const;
	Matrix operator*(const Matrix& matrix) const;
	const MatrixRow<T>& operator[](const size_t index) const;
	MatrixRow<T>& operator[](const size_t index);
};

template<class T>
Matrix<T>::Matrix() noexcept
{
	rows_size = 0;
	columns_size = 0;
	raw_matrix = nullptr;
}

template<class T>
Matrix<T>::Matrix(const std::initializer_list<const std::initializer_list<const T>>& list)
{
	if (!all_initializer_list_sizes_equals(list))
		throw std::invalid_argument("Initializer lists must have equals sizes.");

	rows_size = list.size();
	if (rows_size > 0)
		columns_size = list.begin()->size();
	else
		columns_size = 0;

	raw_matrix = new MatrixRow<T>[rows_size];

	size_t index = 0;
	for (auto sublist : list)
		raw_matrix[index++] = MatrixRow<T>(sublist);
}

template<class T>
Matrix<T>::Matrix(const size_t rows_size, const size_t columns_size)
	: rows_size(rows_size), columns_size(columns_size)
{
	if (rows_size < 0)
		throw std::invalid_argument("Rows size must be greater than 0.");

	if (columns_size < 0)
		throw std::invalid_argument("Columns size must be greater than 0.");

	raw_matrix = new MatrixRow<T>[rows_size];
	for (size_t i = 0; i < rows_size; ++i)
		raw_matrix[i] = MatrixRow<T>(columns_size);
}

template<class T>
Matrix<T>::Matrix(const Matrix& matrix) noexcept
	: rows_size(matrix.rows_size), columns_size(matrix.columns_size)
{
	raw_matrix = new MatrixRow<T>[rows_size];
	for (size_t i = 0; i < rows_size; ++i)
		raw_matrix[i] = matrix.raw_matrix[i];
}

template<class T>
Matrix<T>::Matrix(Matrix&& matrix) noexcept
	: rows_size(matrix.rows_size), columns_size(matrix.columns_size), raw_matrix(matrix.raw_matrix)
{
	matrix.rows_size = -1;
	matrix.columns_size = -1;
	matrix.raw_matrix = nullptr;
}

template<class T>
Matrix<T>::~Matrix() noexcept
{
	delete[] raw_matrix;
}

template<class T>
size_t Matrix<T>::get_rows_size() const
{
	return rows_size;
}

template<class T>
size_t Matrix<T>::get_columns_size() const
{
	return columns_size;
}

template<class T>
Matrix<T> Matrix<T>::transpose() const noexcept
{
	Matrix<T> new_matrix(columns_size, rows_size);

	for (size_t i = 0; i < new_matrix.get_rows_size(); ++i)
		for (size_t j = 0; j < new_matrix.get_columns_size(); ++j)
			new_matrix.raw_matrix[i][j] = raw_matrix[j][i];

	return new_matrix;
}

template<class T>
Matrix<T>& Matrix<T>::operator=(const Matrix& matrix) noexcept
{
	if (&matrix == this)
		return *this;

	delete[] raw_matrix;

	rows_size = matrix.rows_size;
	columns_size = matrix.columns_size;
	raw_matrix = new MatrixRow<T>[rows_size];
	for (size_t i = 0; i < rows_size; ++i)
		raw_matrix[i] = matrix.raw_matrix[i];

	return *this;
}

template<class T>
Matrix<T>& Matrix<T>::operator=(Matrix&& matrix) noexcept
{
	if (&matrix == this)
		return *this;

	delete[] raw_matrix;

	rows_size = matrix.rows_size;
	columns_size = matrix.columns_size;
	raw_matrix = matrix.raw_matrix;

	matrix.rows_size = -1;
	matrix.columns_size = -1;
	matrix.raw_matrix = nullptr;

	return *this;
}

template<class T>
Matrix<T> Matrix<T>::operator+(const Matrix& matrix) const
{
	Matrix<T> new_matrix(*this);

	if (rows_size != matrix.rows_size || columns_size != matrix.columns_size)
		throw std::invalid_argument("Matrix sizes must be equal.");

	for (size_t i = 0; i < rows_size; i++)
		for (size_t j = 0; j < columns_size; j++)
			new_matrix.raw_matrix[i][j] += matrix.raw_matrix[i][j];

	return new_matrix;
}

template<class T>
Matrix<T> Matrix<T>::operator-(const Matrix& matrix) const
{
	Matrix<T> new_matrix(*this);

	if (rows_size != matrix.rows_size || columns_size != matrix.columns_size)
		throw std::invalid_argument("Matrix sizes must be equal.");

	for (size_t i = 0; i < rows_size; i++)
		for (size_t j = 0; j < columns_size; j++)
			new_matrix.raw_matrix[i][j] -= matrix.raw_matrix[i][j];

	return new_matrix;
}

template<class T>
Matrix<T> Matrix<T>::operator*(const Matrix& matrix) const
{
	if (columns_size != matrix.rows_size)
		throw std::invalid_argument("Columns sizes first operand must be equal rows sizes second operand.");

	Matrix<T> new_matrix(rows_size, matrix.columns_size);

	for (size_t i = 0; i < new_matrix.get_rows_size(); ++i)
		for (size_t j = 0; j < new_matrix.get_columns_size(); ++j)
		{
			new_matrix.raw_matrix[i][j] = 0;
			
			for (size_t k = 0; k < columns_size; ++k)
				new_matrix.raw_matrix[i][j] += raw_matrix[i][k] * matrix.raw_matrix[k][j];
		}

	return new_matrix;
}

template<class T>
const MatrixRow<T>& Matrix<T>::operator[](const size_t index) const
{
	if (index < 0 || index >= rows_size)
		throw new std::out_of_range("Index out of range.");

	return raw_matrix[index];
}

template<class T>
MatrixRow<T>& Matrix<T>::operator[](const size_t index)
{
	if (index < 0 || index >= rows_size)
		throw new std::out_of_range("Index out of range.");

	return raw_matrix[index];
}

template<class T>
bool Matrix<T>::all_initializer_list_sizes_equals(const std::initializer_list<const std::initializer_list<const T>>& list) noexcept
{
	auto it = list.begin();

	if (list.size() < 1)
		return true;

	size_t size = (it++)->size();
	while (it != list.end())
	{
		if (it->size() != size)
			return false;

		++it;
	}

	return true;
}