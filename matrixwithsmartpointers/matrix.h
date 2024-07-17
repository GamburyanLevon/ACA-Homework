#pragma once
#include <memory>
#include <iostream>

template <typename T>
class Matrix
{
private:
    std::unique_ptr<T[]> data;
    int rows, cols;

public:
    Matrix(int rows, int cols);

    Matrix(Matrix &&other) noexcept;

    Matrix &operator=(Matrix &&other) noexcept;

    T &operator()(int row, int col);

    const T &operator()(int row, int col) const;

    int getRows() const;

    int getCols() const;
};