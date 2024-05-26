template <typename T>
Vector<T>::Vector() : data(nullptr), size(0), cap(0) {}

template <typename T>
Vector<T>::Vector(const int& size) : data(nullptr), size(size), cap(2*size) {}


template <typename T>
Vector<T>::~Vector() 
{
    delete[] data;
}

template <typename T>
void Vector<T>::push_back(const T& value) 
{
    if (size == cap) 
    {
        resize(cap == 0 ? 1 : 2 * cap);
    }
    data[size++] = value;
}

template <typename T>
T& Vector<T>::operator[](int index) 
{
    return data[index];
}

template <typename T>
int Vector<T>::length() const 
{
    return size;
}

template <typename T>
int Vector<T>::capacity() const 
{
    return cap;
}

template <typename T>
void Vector<T>::resize(const int& new_capacity) 
{
    T* new_data = new T[new_capacity];
    for (int i = 0; i < size; ++i) 
    {
        new_data[i] = data[i];
    }
    delete[] data;
    data = new_data;
    cap = new_capacity;
}