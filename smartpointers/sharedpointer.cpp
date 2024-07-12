#include <iostream>
#include "sharedpointer.h"

template <typename T>
void SharedPointer<T>::release()
{
    if (refCount)
    {
        --(*refCount);
        if (*refCount == 0)
        {
            delete ptr;
            delete refCount;
        }
    }
}

template <typename T>
SharedPointer<T>::SharedPointer(T *p) : ptr(p), refCount(p ? new int(1) : nullptr) {}

template <typename T>
SharedPointer<T>::SharedPointer(const SharedPointer<T> &sp) : ptr(sp.ptr), refCount(sp.refCount)
{
    if (refCount)
    {
        ++(*refCount);
    }
}

template <typename T>
SharedPointer<T>::SharedPointer(SharedPointer<T> &&sp) noexcept
    : ptr(sp.ptr), refCount(sp.refCount)
{
    sp.ptr = nullptr;
    sp.refCount = nullptr;
}

template <typename T>
SharedPointer<T>::~SharedPointer()
{
    release();
}

template <typename T>
SharedPointer<T> &SharedPointer<T>::operator=(const SharedPointer<T> &sp)
{
    if (this != &sp)
    {
        release();
        ptr = sp.ptr;
        refCount = sp.refCount;
        if (refCount)
        {
            ++(*refCount);
        }
    }
    return *this;
}

template <typename T>
SharedPointer<T>& SharedPointer<T>::operator=(SharedPointer<T> &&sp) noexcept
{
    if (this != &sp)
    {
        release();
        ptr = sp.ptr;
        refCount = sp.refCount;
        sp.ptr = nullptr;
        sp.refCount = nullptr;
    }
    return *this;
}

template <typename T>
T &SharedPointer<T>::operator*() const
{
    return *ptr;
}

template <typename T>
T *SharedPointer<T>::operator->() const
{
    return ptr;
}

template <typename T>
int SharedPointer<T>::use_count() const
{
    return refCount ? *refCount : 0;
}

template class SharedPointer<int>;
