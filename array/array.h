#pragma once
#include <iostream>

class Array {
private:
    int *arr;
    int size;

public:
    Array(int size);
    Array(int *arr, int size);
    Array(const Array &other);
    ~Array();
    void init();
    int& operator[](int index);
    friend std::ostream& operator<<(std::ostream &out, const Array &array);
};
