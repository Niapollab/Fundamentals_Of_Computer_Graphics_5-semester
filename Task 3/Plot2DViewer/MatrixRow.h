#pragma once
#include <stdexcept>
#include <initializer_list>

template<class T>
class MatrixRow
{
private:
	size_t size;
	T* elements;

public:
	MatrixRow() noexcept;
	MatrixRow(const std::initializer_list<const T>& list) noexcept;
	MatrixRow(const size_t size);
	MatrixRow(const MatrixRow& matrix_row) noexcept;
	MatrixRow(MatrixRow&& matrix_row) noexcept;
	~MatrixRow() noexcept;

	size_t get_size() const noexcept;
	MatrixRow& operator=(const MatrixRow& matrix_row) noexcept;
	MatrixRow& operator=(MatrixRow&& matrix_row) noexcept;
	const T& operator[](const size_t index) const;
	T& operator[](const size_t index);
};

template<class T>
MatrixRow<T>::MatrixRow() noexcept
{
	size = 0;
	elements = nullptr;
}

template<class T>
MatrixRow<T>::MatrixRow(const std::initializer_list<const T>& list) noexcept
{
	size = list.size();
	elements = new T[size];

	size_t index = 0;
	for (const T& element : list)
		elements[index++] = element;
}

template<class T>
MatrixRow<T>::MatrixRow(const size_t size)
	: size(size)
{
	if (size < 0)
		throw std::invalid_argument("Size must be greater than 0.");
	
	elements = new T[size];
	for (size_t i = 0; i < size; ++i)
		elements[i] = 0;
}

template<class T>
MatrixRow<T>::MatrixRow(const MatrixRow& matrix_row) noexcept
	: size(matrix_row.size)
{
	elements = new T[size];
	for (size_t i = 0; i < size; ++i)
		elements[i] = matrix_row.elements[i];
}

template<class T>
MatrixRow<T>::MatrixRow(MatrixRow&& matrix_row) noexcept
	: size(matrix_row.size), elements(matrix_row.elements)
{
	matrix_row.size = -1;
	matrix_row.elements = nullptr;
}

template<class T>
MatrixRow<T>::~MatrixRow() noexcept
{
	delete[] elements;
}

template<class T>
size_t MatrixRow<T>::get_size() const noexcept
{
	return size;
}

template<class T>
MatrixRow<T>& MatrixRow<T>::operator=(const MatrixRow& matrix_row) noexcept
{
	if (&matrix_row == this)
		return *this;

	delete[] elements;

	size = matrix_row.size;
	elements = new T[size];
	for (size_t i = 0; i < size; ++i)
		elements[i] = matrix_row.elements[i];

	return *this;
}

template<class T>
MatrixRow<T>& MatrixRow<T>::operator=(MatrixRow&& matrix_row) noexcept
{
	if (&matrix_row == this)
		return *this;

	delete[] elements;

	size = matrix_row.size;
	elements = matrix_row.elements;

	matrix_row.size = -1;
	matrix_row.elements = nullptr;

	return *this;
}

template<class T>
const T& MatrixRow<T>::operator[](const size_t index) const
{
	if (index < 0 || index >= size)
		throw new std::out_of_range("Index out of range.");

	return elements[index];
}

template<class T>
T& MatrixRow<T>::operator[](const size_t index)
{
	if (index < 0 || index >= size)
		throw new std::out_of_range("Index out of range.");

	return elements[index];
}