#include "matrix.h"
#include <iostream>


int main() 
{
    int m, n;
    std::cin >> m >> n;

    Matrix m1(m, n);
    m1.initialize();
    m1.printMatrix();

    Matrix m2(m1);
    m2++;
    m2.printMatrix();

    Matrix m4(m,n);
    m4 = m1 + m2;
    ++m4;
    m4.printMatrix();

    return 0;
}