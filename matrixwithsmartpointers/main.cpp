#include <iostream>
#include "matrix.h"

int main()
{
    int rows = 3;
    int cols = 3;
    Matrix<int> matrix(rows, cols);

    for (int i = 0; i < rows; ++i)
    {
        for (int j = 0; j < cols; ++j)
        {
            matrix(i, j) = i * cols + j + 1;
        }
    }

    for (int i = 0; i < rows; ++i)
    {
        for (int j = 0; j < cols; ++j)
        {
            std::cout << matrix(i, j) << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}