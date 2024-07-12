#include "smartpointer.h"
#include "sharedpointer.h"
#include <iostream>

int main() {
    // SmartPointer<int> sp1(new int(6));

    // std::cout << *sp1 << std::endl;

    // SmartPointer<int> sp2(new int[6], true);

    // for (int i = 0; i < 6; i++)
    // {
    //     sp2[i] = i+1;
    // }
    // for (int i = 0; i < 6; i++)
    // {
    //     std::cout << sp2[i] << std::endl;
    // }
    {
        SharedPointer<int> sp1(new int(10));
        {
            SharedPointer<int> sp2 = sp1;
            std::cout << "sp1 count: " << sp1.use_count() << std::endl; 

            std::cout << "sp2: " << *sp2 << std::endl; 
        } 

        std::cout << "sp1 count oout of scope: " << sp1.use_count() << std::endl; 
        std::cout << "sp1: " << *sp1 << std::endl; 
    } 

    return 0;
}