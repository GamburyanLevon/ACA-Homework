#include <iostream>
#include <fstream>
#include <cstdlib> // for std::rand() and std::srand()
#include <ctime>   // for std::time()
#include "matrix.h"

template <typename T>
void generateRandomMatrix(const std::string& filename, size_t rows, size_t cols) 
{
    std::ofstream outfile(filename);
    if (!outfile) 
    {
        std::cout << ("Cannot open file " + filename);
    }

    outfile << rows << " " << cols << std::endl;
    std::srand(std::time(0));

    for (size_t i = 0; i < rows; ++i) 
    {
        for (size_t j = 0; j < cols; ++j) 
        {
            T value = static_cast<T>(std::rand() % 100);
            outfile << value << " ";
        }
        outfile << std::endl;
    }
}

template <typename T>
Matrix<T> readMatrixFromFile(const std::string& filename) 
{
    std::ifstream infile(filename);
    if (!infile) 
    {
        std::cout << ("Cannot open file " + filename);
    }

    int rows, cols;
    infile >> rows >> cols;

    Matrix<T> matrix(rows, cols);
    T value;
    for (size_t i = 0; i < rows; ++i) {
        for (size_t j = 0; j < cols; ++j) {
            infile >> value;
            matrix.set(i, j, value);
        }
    }

    return matrix;
}

template <typename T>
void writeMatrixToFile(const Matrix<T>& matrix, const std::string& filename) 
{
    std::ofstream outfile(filename);
    if (!outfile) 
    {
        std::cout << ("Cannot open file " + filename);
    }

    outfile << matrix.getRows() << " " << matrix.getCols() << std::endl;
    matrix.print(outfile);
}

int main() {
    int rows1 = 3, cols1 = 2; 
    int rows2 = 2, cols2 = 3;

    generateRandomMatrix<int>("matrix1.txt", rows1, cols1);
    generateRandomMatrix<int>("matrix2.txt", rows2, cols2);

    Matrix<int> mat1 = readMatrixFromFile<int>("matrix1.txt");
    Matrix<int> mat2 = readMatrixFromFile<int>("matrix2.txt");

    Matrix<int> result = mat1 * mat2;

    writeMatrixToFile(result, "result.txt");

    return 0;
}
