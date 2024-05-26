#include <iostream>
#include "vector.h"

int main() {
    Vector<int> vec;
    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(3);
    vec.push_back(4);

    for (int i = 0; i < vec.length(); i++) 
    {
        std::cout << vec[i] << " ";
    }
    std::cout << std::endl;
    std::cout << vec.length() <<std::endl;


    return 0;
}
