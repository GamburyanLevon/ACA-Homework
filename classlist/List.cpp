#include <iostream>
#include "List.h"

template<typename T>
void List<T>::resize(int new_capacity) 
{
    T* new_data = new T[new_capacity];
    for (size_t i = 0; i < size; ++i) 
    {
        new_data[i] = data[i];
    }
    delete[] data;
    data = new_data;
    capacity = new_capacity;
}

template<typename T>
List<T>::List() : data(nullptr), capacity(0), size(0) 
{
    resize(1);
}

template<typename T>
List<T>::~List() 
{
    delete[] data;
}

template<typename T>
void List<T>::append(const T& item) 
{
    if (size == capacity) 
    {
        resize(capacity * 2);
    }
    data[size++] = item;
}

template<typename T>
void List<T>::insert(int index, const T& item) 
{
    if (index > size) 
    {
        std::cout << "Index out of range" << std::endl;
        return;
    }
    if (size == capacity) 
    {
        resize(capacity * 2);
    }
    for (size_t i = size; i > index; --i) 
    {
        data[i] = data[i - 1];
    }
    data[index] = item;
    ++size;
}

template<typename T>
void List<T>::remove(int index) 
{
    if (index >= size) 
    {
        std::cout << "Index out of range" << std::endl;
        return;
    }
    for (size_t i = index; i < size - 1; ++i) 
    {
        data[i] = data[i + 1];
    }
    --size;
}

template<typename T>
T& List<T>::operator[](int index) 
{
    return data[index];
}

template<typename T>
const T& List<T>::operator[](int index) const 
{
    return data[index];
}

template<typename T>
size_t List<T>::get_size() const 
{
    return size;
}

template<typename T>
bool List<T>::is_empty() const 
{
    return size == 0;
}


template class List<int>;
template class List<std::string>;
template class List<double>;
