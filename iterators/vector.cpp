#include <iostream>
#include <vector>
#include <cmath>

bool isPrime(int n)
{
    if(n <= 1)
    {
        return true;
    }
    for (int i = 2; i <= sqrt(n); i++)
    {
        if (n%i == 0)
        {
            return false;
        }
    }
    return true;
}

void erase(std::vector<int>& vec)
{
    auto it = vec.begin();
    while (it != vec.end())
    {
        if (isPrime(*it))
        {
            it = vec.erase(it);
        }
        else
        {
            ++it;
        }
    }
}

int main()
{
    std::vector<int> vec = {1, 7, 9, 25, 2, 8};
    erase(vec);
    for (auto i = vec.begin(); i != vec.end(); i++)
    {
        std::cout << *i << " ";
    }
    std::cout << std::endl;

    return 0;
}