#pragma once

template <typename T>
class SharedPointer {
private:
    T* ptr; 
    int* refCount;

    void release();

public:
    explicit SharedPointer(T* p = nullptr);

    SharedPointer(const SharedPointer& sp);

    SharedPointer(SharedPointer&& sp) noexcept;

    ~SharedPointer();

    SharedPointer& operator=(const SharedPointer& sp);

    SharedPointer& operator=(SharedPointer&& sp) noexcept;
    
    T& operator*() const;

    T* operator->() const;

    int use_count() const;
};

