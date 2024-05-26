template <typename T>
Matrix<T>::Matrix(const int& rows, const int& cols) : rows(rows), cols(cols) 
{
    data = new T*[rows];
    for (size_t i = 0; i < rows; i++) 
    {
        data[i] = new T[cols]();
    }
}

template <typename T>
Matrix<T>::~Matrix() 
{
    for (size_t i = 0; i < rows; i++)
    {
        delete[] data[i];
    }
    delete[] data;
}

template <typename T>
void Matrix<T>::set(const int& row, const int& col, const T& value) 
{
    data[row][col] = value;
}

template <typename T>
T Matrix<T>::get(const int& row, const int& col) const 
{
    return data[row][col];
}

template <typename T>
int Matrix<T>::getRows() const 
{
    return rows;
}

template <typename T>
int Matrix<T>::getCols() const 
{
    return cols;
}

template <typename T>
Matrix<T> Matrix<T>::operator*(const Matrix<T>& other) const 
{
    if (cols != other.getRows()) 
    {
        std::cout << "cant multiply";
        return *this;
    }

    Matrix<T> result(rows, other.getCols());
    for (size_t i = 0; i < rows; ++i) 
    {
        for (size_t j = 0; j < other.getCols(); ++j) 
        {
            for (size_t k = 0; k < cols; ++k) 
            {
                result.data[i][j] += data[i][k] * other.get(k, j);
            }
        }
    }
    return result;
}

template <typename T>
void Matrix<T>::print(std::ostream& out) const 
{
    for (int i = 0; i < rows; ++i) 
    {
        for (int j = 0; j < cols; ++j) 
        {
            out << data[i][j] << " ";
        }
        out << std::endl;
    }
}

