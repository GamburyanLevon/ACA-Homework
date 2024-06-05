#pragma once
#include "node.h"

template <typename T>
class List 
{
private:
    Node<T>* head;

public:
    List();
    void insert(T data);
    void push_front(T data);
    void pop_front();
    void print() const;
    bool hasLoop() const;
    void createLoop(int);
    void reverse();
    void find(int);
};


