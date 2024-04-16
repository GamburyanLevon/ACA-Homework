#include <iostream>

void printMatrix(int* matrix, int m) 
{
    for (int i = 0; i < m; i++) 
    {
        for (int j = 0; j < m; j++) 
        {
            std::cout << matrix[i * m + j] << " ";
        }
        std::cout << std::endl;
    }
}

void rotateMatrix(int* matrix, int m) 
{
   for (int i = 0; i < m / 2; i++) 
   {
        for (int j = i; j < m - i - 1; j++) 
        {
            int temp = matrix[i * m + j];
            matrix[i * m + j] = matrix[(m - 1 - j) * m + i];
            matrix[(m - 1 - j) * m + i] = matrix[(m - 1 - i) * m + (m - 1 - j)];
            matrix[(m - 1 - i) * m + (m - 1 - j)] = matrix[j * m + (m - 1 - i)];
            matrix[j * m + (m - 1 - i)] = temp;
        }
    }
}

int main() 
{
    int m;
    std::cin >> m;

    int* matrix = new int[m];

    for (int i = 0; i < m; i++) 
    {
        matrix[i] = i + 1;
    }

    rotateMatrix(matrix, m);

    printMatrix(matrix, m);

    delete[] matrix;

    return 0;
}
