#include <iostream>

class Matrix
{
public:
    Matrix(int m, int n)
    {
        cols = m;
        rows = n;
        mat = new int*[cols];
        for (int i = 0; i < cols; i++)
        {
            mat[i] = new int[rows];
        }
    }
    ~Matrix()
    {
        for (int i = 0; i < cols; i++)
        {
            delete[] mat[i];
        }
        delete[] mat;
    }
    int& operator()(int i, int j)
    {
        return mat[i][j];
    }
    void initialize()
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
    void printMatrix()
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
    void convertMatrix(Matrix& newmat) 
    {
        
        for (int i = 0; i < rows; i++) 
        {
            for (int j = 0; j < cols; j++) 
            {
                newmat(i, j) = mat[j][i];
            }
        }
    }
private:
    int rows;
    int cols;
    int** mat;
};


int main() 
{
    int m, n;
    std::cin >> m >> n;
    Matrix matrix(m, n);
    matrix.initialize();
    matrix.printMatrix();
    std::cout << std::endl;
    Matrix newmat(n, m);
    matrix.convertMatrix(newmat);
    newmat.printMatrix();
    return 0;
}



