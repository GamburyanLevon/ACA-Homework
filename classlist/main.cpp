#include <iostream>
#include "List.h"

int main() 
{
    List<int> myList;
    myList.append(1);
    myList.append(2);
    myList.append(3);
    myList.insert(1, 4);

    for (int i = 0; i < myList.get_size(); ++i) 
    {
        std::cout << myList[i] << " ";
    }

    std::cout << std::endl;

    myList.remove(0);

    for (int i = 0; i < myList.get_size(); ++i) 
    {
        std::cout << myList[i] << " ";
    }

    std::cout << std::endl;

    return 0;
}