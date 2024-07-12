#pragma once

template <typename T>
class SmartPointer {
private:
    T* ptr;
    bool isArray;

public:
    explicit SmartPointer(T* p = nullptr);

    explicit SmartPointer(T* p, bool arrayFlag) : ptr(p), isArray(arrayFlag) {}

    ~SmartPointer();

    T& operator*() const;

    T* operator->() const;

    T& operator[](int index) const;

    SmartPointer(const SmartPointer&) = delete;
    SmartPointer& operator=(const SmartPointer&) = delete;

    SmartPointer(SmartPointer&& sp) noexcept;

    SmartPointer& operator=(SmartPointer&& sp) noexcept;
};