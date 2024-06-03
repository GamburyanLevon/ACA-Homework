#include "list.h"
#include <iostream>


int main() 
{
    List<int> list;
    
    list.insert(10);
    list.insert(20);
    list.insert(30);
    list.print();

    list.push_front(5);
    list.push_front(0);
    list.print();

    list.pop_front();
    list.print();
    list.pop_front();
    list.print();

    std::cout << "Has loop: " << std::boolalpha << list.hasLoop() << std::endl;

    list.createLoop(2);

    std::cout << "Has loop: " << std::boolalpha << list.hasLoop() << std::endl;

    return 0;
}
