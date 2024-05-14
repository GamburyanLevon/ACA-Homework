#pragma once

class Matrix
{
public:
    Matrix(int, int);
    ~Matrix();
    Matrix(const Matrix&);
    Matrix& operator=(const Matrix& );
    Matrix operator+(const Matrix& ) const;
    int& operator()(int , int );
    int operator()(int , int ) const;
    void initialize();
    void printMatrix();
    Matrix& operator++();
    Matrix operator++(int);
   
private:
    int rows;
    int cols;
    int** mat;
};
