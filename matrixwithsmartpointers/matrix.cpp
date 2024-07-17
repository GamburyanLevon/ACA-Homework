#include "matrix.h"

template <typename T>
std::unique_ptr<T[]> make_unique_array(int size)
{
    return std::unique_ptr<T[]>(new T[size]);
}

template <typename T>
Matrix<T>::Matrix(int rows, int cols)
    : rows(rows), cols(cols), data(make_unique_array<T>(rows * cols)) {}

template <typename T>
Matrix<T>::Matrix(Matrix<T> &&other) noexcept
    : data(std::move(other.data)), rows(other.rows), cols(other.cols)
{
    other.rows = 0;
    other.cols = 0;
}

template <typename T>
Matrix<T> &Matrix<T>::operator=(Matrix<T> &&other) noexcept
{
    if (this != &other)
    {
        data = std::move(other.data);
        rows = other.rows;
        cols = other.cols;
        other.rows = 0;
        other.cols = 0;
    }
    return *this;
}

template <typename T>
T &Matrix<T>::operator()(int row, int col)
{
    if (row >= rows || col >= cols)
    {
        throw std::out_of_range("Index out of range");
    }
    return data[row * cols + col];
}

template <typename T>
const T &Matrix<T>::operator()(int row, int col) const
{
    if (row >= rows || col >= cols)
    {
        throw std::out_of_range("Index out of range");
    }
    return data[row * cols + col];
}

template <typename T>
int Matrix<T>::getRows() const
{
    return rows;
}

template <typename T>
int Matrix<T>::getCols() const
{
    return cols;
}

template class Matrix<int>;