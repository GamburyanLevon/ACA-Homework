#pragma once
#include "/Users/levon/Desktop/aca/vector/vector.h"

template <typename T>
class Stack
{
private:
    Vector<T> stack;

public:
    Stack() = default;
    void push(const T&);
    void pop();
    T& top();
    bool isEmpty();
    void printStack();
};