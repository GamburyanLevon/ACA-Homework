#include <iostream>
#include <utility>

template <typename T1, typename T2>
std::pair<T1, T2> make_pair(T1&& t1, T2&& t2) 
{
    return std::pair<T1, T2>(std::forward<T1>(t1), std::forward<T2>(t2));
}

int main() 
{
    auto a = make_pair(1, 2.5);
    auto b = make_pair("1234", "789");

    std::cout << a.first << " " << a.second << "\n";
    std::cout << b.first << " " << b.second << "\n";

    return 0;
}
