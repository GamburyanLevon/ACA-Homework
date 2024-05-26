#pragma once

template <typename T>
class Vector 
{
public:
    Vector();
    Vector(const int&);
    ~Vector();

    void push_back(const T& value);
    T& operator[](int index);
    int length() const;
    int capacity() const;

private:
    void resize(const int&);

    T* data;
    int size;
    int cap;
};

#include "vector.tpp"
