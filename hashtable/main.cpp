#include <iostream>
#include "hashtable.h"

int main() 
{
    HashTable ht(9);

    ht.insertItem(1, "value1");
    ht.insertItem(2, "value2");
    ht.insertItem(11, "value11");
    ht.insertItem(21, "value21");
    ht.insertItem(19, "value19");
    ht.insertItem(23, "value23");
    ht.insertItem(17, "value17");
    ht.insertItem(5, "value5");
    ht.insertItem(7, "value7");
    ht.insertItem(47, "value47");
    ht.insertItem(104, "value104");

    ht.displayHashTable();

    std::cout << ht.searchItem(21) << std::endl;

    ht.deleteItem(21);

    ht.displayHashTable();

    std::cout << ht.searchItem(21) << std::endl;

    return 0;
}
