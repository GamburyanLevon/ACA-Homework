#pragma once
#include <initializer_list>

template <typename T>
class Vector
{
public:
    Vector();
    Vector(std::initializer_list<T>);
    Vector(Vector &&);
    Vector(const Vector &);
    Vector(const int &);
    ~Vector();
    Vector &operator=(const Vector &);
    Vector &operator=(Vector &&);
    void push_back(const T &value);
    void pop_back();
    void push_front(const T &value);
    void pop_front();
    void insert(const int &, const T &);
    T &operator[](const int &);
    int length() const;
    bool empty() const;
    T &back();
    void reserve(int);
    class Iterator
    {
    public:
        Iterator(T *ptr) : current(ptr) {}
        T &operator*()
        {
             return *current; 
        }
        Iterator &operator++()
        {
            ++current;
            return *this;
        }
        Iterator &operator--()
        {
            --current;
            return *this;
        }

        bool operator!=(const Iterator &other) const
        {
            return current != other.current; 
        }

    private:
        T *current;
    };

    Iterator begin() { return Iterator(data); }
    Iterator end() { return Iterator(data + size); }
    Iterator rbegin() { return Iterator(data + size - 1); }
    Iterator rend() { return Iterator(data - 1); }

private:
    void resize();

    T *data;
    int size;
    int cap;
};
