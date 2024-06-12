#include <iostream>
#include <list>

double mijin(std::list<int>& l)
{
    auto it = l.begin();
    int count = 0;
    int sum = 0;
    while (it != l.end())
    {
        count++;
        sum += *it;
        ++it;
    }
    return (double)sum/count;
}

void erase(std::list<int>& l)
{
    double min = mijin(l);
    auto it = l.begin();
    while (it != l.end())
    {
        if (*it < min)
        {
            it = l.erase(it);
        }
        else
        {
            ++it;
        }
    }
}

int main()
{
    std::list<int> mylist = {1, 7, 9, 25, 2, 8};

    erase(mylist);

    for (auto i = mylist.begin(); i != mylist.end(); i++)
    {
        std::cout << *i << " ";
    }
    std::cout << std::endl;

    return 0;
}