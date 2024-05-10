#include "array.h"

Array::Array(int size) : size(size)
{
    arr = new int[size];
    init();
}

Array::Array(int *obj, int size) : size(size)
{
    arr = new int[size];
    for (int i = 0; i < size; ++i) 
    {
        arr[i] = obj[i];
    }
}

Array::Array(const Array &obj) 
{
    size = obj.size;
    arr = new int[size];
    for (int i = 0; i < size; ++i) 
    {
        arr[i] = obj.arr[i];
    }
}

Array::~Array() 
{
    delete[] arr;
}

void Array::init() 
{
    for (int i = 0; i < size; ++i) 
    {
        arr[i] = i + 1;
    }
}

int& Array::operator[](int index) 
{
    return arr[index];
}

std::ostream& operator<<(std::ostream &out, const Array &array) 
{
    out << "[ ";
    for (int i = 0; i < array.size; ++i) {
        out << array.arr[i] << " ";
    }
    out << "]";
    return out;
}
