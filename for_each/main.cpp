#include <iostream>
#include <vector>

template <typename Itr, typename Fnc>
Fnc my_for_each(Itr first, Itr last, Fnc func) 
{
    while (first != last) 
    {
        func(*first);
        ++first;
    }
    return func;
}

void print(int x)
{
    std::cout << x << " ";
}

int main() 
{
    std::vector<int> vec = {1, 2, 3, 4, 5};

    my_for_each(vec.begin(), vec.end(), print);
    std::cout << std::endl;

    return 0;
}
