#include <iostream>
#include "matrix.h"
#include <fstream>
#include <ctime>
#include <sstream>

Matrix::Matrix(int r, int c) : rows(r), cols(c), data(nullptr)
{
    data = new int *[rows];
    for (int i = 0; i < rows; ++i)
        data[i] = new int[cols]();
}

Matrix::~Matrix()
{
    if (data != nullptr)
    {
        for (int i = 0; i < rows; ++i)
            delete[] data[i];
        delete[] data;
    }
}

Matrix::Matrix()
{
    data = nullptr;
}

void Matrix::readFromFile(const std::string &filename)
{
    std::ifstream file(filename);
    if (!file.is_open())
    {
        std::cerr << "Error opening file: " << filename << std::endl;
        return;
    }

    rows = 0;
    cols = 0;
    std::string line;
    while (getline(file, line))
    {
        ++rows;
        std::istringstream iss(line);
        int colCount = 0;
        int value;
        while (iss >> value)
        {
            ++colCount;
        }
        if (cols == 0)
        {
            cols = colCount;
        }
        else if (colCount != cols)
        {
            std::cerr << "Error: Inconsistent number of columns in the file." << std::endl;
            file.close();
            return;
        }
    }

    file.clear();
    file.seekg(0);

    data = new int *[rows];
    for (int i = 0; i < rows; ++i)
        data[i] = new int[cols];

    for (int i = 0; i < rows; ++i)
    {
        for (int j = 0; j < cols; ++j)
        {
            if (!(file >> data[i][j]))
            {
                std::cerr << "Error reading from file: " << filename << std::endl;
                file.close();
                return;
            }
        }
    }

    file.close();
}

void Matrix::multiply(const Matrix &other, Matrix &result) const
{
    if (cols != other.rows)
    {
        std::cout << "Matrix dimensions incompatible for multiplication" << std::endl;
        return;
    }

    if (result.data != nullptr)
    {
        for (int i = 0; i < result.rows; ++i)
            delete[] result.data[i];
        delete[] result.data;
    }
    result.rows = rows;
    result.cols = other.cols;
    result.data = new int *[result.rows];
    for (int i = 0; i < result.rows; ++i)
        result.data[i] = new int[result.cols]();

    if (data == nullptr || other.data == nullptr)
    {
        std::cerr << "Error: Matrix data is not initialized properly." << std::endl;
        return;
    }

    for (int i = 0; i < rows; ++i)
    {
        for (int j = 0; j < other.cols; ++j)
        {
            for (int k = 0; k < cols; ++k)
            {
                result.data[i][j] += data[i][k] * other.data[k][j];
            }
        }
    }
}

void Matrix::writeToFile(const std::string &filename) const
{
    std::ofstream file(filename);
    if (!file.is_open())
    {
        std::cerr << "Error opening file: " << filename << std::endl;
        return;
    }

    for (int i = 0; i < rows; ++i)
    {
        for (int j = 0; j < cols; ++j)
        {
            file << data[i][j] << " ";
        }
        file << std::endl;
    }

    file.close();
}

int Matrix::generateRandomInt(int min, int max)
{
    return min + rand() % (max - min + 1);
}
void Matrix::randominit()
{
    for (int i = 0; i < rows; ++i)
    {
        for (int j = 0; j < cols; ++j)
        {
            data[i][j] = generateRandomInt(0, 100);
        }
    }
}

int Matrix::getC()
{
    return cols;
}
int Matrix::getR()
{
    return cols;
}