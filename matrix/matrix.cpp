#include <iostream>
#include "matrix.h"

Matrix::Matrix(int m, int n)
{
    std::cout << "call param constructor" << std::endl;
    cols = m;
    rows = n;
    mat = new int *[cols];
    for (int i = 0; i < cols; i++)
    {
        mat[i] = new int[rows];
    }
}
Matrix::~Matrix()
{
    std::cout << "call destructor" << std::endl;
    for (int i = 0; i < cols; i++)
    {
        delete[] mat[i];
    }
    delete[] mat;
}
Matrix::Matrix(const Matrix &obj)
{
    std::cout << "call copy constructor" << std::endl;
    this->cols = obj.cols;
    this->rows = obj.rows;
    mat = new int *[cols];
    for (int i = 0; i < cols; ++i)
    {
        mat[i] = new int[rows];
        for (int j = 0; j < rows; ++j)
        {
            mat[i][j] = obj.mat[i][j];
        }
    }
}
Matrix &Matrix::operator=(const Matrix &obj)
{
    std::cout << "call assignment constructor" << std::endl;
    if (this == &obj)
    {
        return *this;
    }
    for (int i = 0; i < cols; ++i)
    {
        delete[] mat[i];
    }
    delete[] mat;
    this->cols = obj.cols;
    this->rows = obj.rows;
    this->mat = new int *[cols];
    for (int i = 0; i < cols; ++i)
    {
        mat[i] = new int[rows];
    }
    for (int i = 0; i < cols; i++)
    {
        for (int j = 0; j < rows; ++j)
        {
            mat[i][j] = obj.mat[i][j];
        }
    }
    return *this;
}
Matrix Matrix::operator+(const Matrix &obj) const
{
    if (rows != obj.rows || cols != obj.cols)
    {
        std::cout << "cannot add." << std::endl;
        return *this;
    }
    Matrix result(cols, rows);
    for (int i = 0; i < cols; ++i)
    {
        for (int j = 0; j < rows; ++j)
        {
            result(i, j) = mat[i][j] + obj(i, j);
        }
    }
    return result;
}
int &Matrix::operator()(int i, int j)
{
    return mat[i][j];
}
int Matrix::operator()(int i, int j) const
{
    return mat[i][j];
}
void Matrix::initialize()
{
    int count = 1;
    for (int i = 0; i < cols; i++)
    {
        for (int j = 0; j < rows; j++)
        {
            mat[i][j] = count;
            count++;
        }
    }
}
void Matrix::printMatrix()
{
    for (int i = 0; i < cols; i++)
    {
        for (int j = 0; j < rows; j++)
        {
            std::cout << mat[i][j] << " ";
        }
        std::cout << std::endl;
    }
}
Matrix& Matrix::operator++()
{
    for (int i = 0; i < cols; i++)
    {
        for (int j = 0; j < rows; j++)
        {
            mat[i][j] += 3;
        }
    }
    return *this;
}
Matrix Matrix::operator++(int)
{
    Matrix temp(*this);
    ++(*this);
    return temp;
}