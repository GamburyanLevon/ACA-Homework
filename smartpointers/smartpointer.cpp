#include "smartpointer.h"
#include <iostream>

template <typename T>
SmartPointer<T>::SmartPointer(T *p) : ptr(p) {}

template <typename T>
SmartPointer<T>::~SmartPointer()
{
    if (isArray)
    {
        delete[] ptr;
    }
    else
    {
        delete ptr;
    }
}

template <typename T>
T &SmartPointer<T>::operator*() const
{
    return *ptr;
}

template <typename T>
T *SmartPointer<T>::operator->() const
{
    return ptr;
}

template <typename T>
T &SmartPointer<T>::operator[](int index) const
{
    if (isArray)
    {
        return ptr[index];
    }
    std::cout << "is not an array";
}

template <typename T>
SmartPointer<T>::SmartPointer(SmartPointer&& sp) noexcept : ptr(sp.ptr)
{
    sp.ptr = nullptr;
}

template <typename T>
SmartPointer<T>& SmartPointer<T>::operator=(SmartPointer&& sp) noexcept
{
    if (this != &sp)
    {
        delete[] ptr;
        ptr = sp.ptr;
        isArray = sp.isArray;
        sp.ptr = nullptr;
    }
    return *this;
}

template class SmartPointer<int>;
