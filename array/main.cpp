#include "array.h"

int main() {
    Array arr1(5);
    std::cout << "Array 1: " << arr1 << std::endl;

    int obj[] = {1, 2, 3, 4, 5};
    Array arr2(obj, 5);
    std::cout << "Array 2: " << arr2 << std::endl;

    Array arr3(arr1);
    std::cout << "Array 3 (copy of Array 1): " << arr3 << std::endl;

    std::cout << "Value at index 2 of Array 2: " << arr2[2] << std::endl;
    std::cout << ++arr2 << std::endl;
    arr1++;
    std::cout << arr1 <<std::endl;
    return 0;
}
