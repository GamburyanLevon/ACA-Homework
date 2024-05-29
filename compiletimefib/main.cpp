#include <iostream>

template<unsigned int T>
struct Fibonacci 
{
    static const unsigned long long value = Fibonacci<T-1>::value + Fibonacci<T-2>::value;
};

template<>
struct Fibonacci<0> 
{
    static const unsigned long long value = 0;
};

template<>
struct Fibonacci<1> 
{
    static const unsigned long long value = 1;
};

int main() 
{
    std::cout << "Fibonacci(10) = " << Fibonacci<10>::value << std::endl;
    std::cout << "Fibonacci(20) = " << Fibonacci<20>::value << std::endl;
    std::cout << "Fibonacci(1) = " << Fibonacci<1>::value << std::endl;

    return 0;
}
