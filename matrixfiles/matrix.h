#pragma once
#include <string>

template <typename T>
class Matrix {
private:
    T** data;
    int rows, cols;

public:
    Matrix(const int&,const int&);
    ~Matrix();
    void set(const int&,const int&, const T&);
    T get(const int&, const int&l) const;
    int getRows() const;
    int getCols() const;
    Matrix<T> operator*(const Matrix<T>& other) const;
    void print(std::ostream& out) const;
};

#include "matrix.tpp"
