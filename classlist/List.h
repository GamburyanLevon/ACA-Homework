#pragma once

template<typename T>
class List 
{
private:
    T* data;
    int capacity;
    int size;

    void resize(int);
public:
    List();
    ~List();
    void append(const T&);
    void insert(int, const T&);
    void remove(int);
    T& operator[](int);
    const T& operator[](int) const;
    size_t get_size() const;
    bool is_empty() const;
};
