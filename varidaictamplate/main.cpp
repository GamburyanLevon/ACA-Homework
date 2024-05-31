#include <iostream>

void print() 
{
    std::cout << std::endl;
}

template<typename T, typename... Args>
void print(const T& first, const Args&... args) 
{
    std::cout << first << ' ';
    print(args...);
}

int main() 
{
    print(1, "142312dq", "Hello", 3.14, 'a');
    return 0;
}
