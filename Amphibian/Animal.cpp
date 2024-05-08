#include "Animal.h"
#include <iostream>

Animal::Animal(const int& age) : m_age(age) {}

void Animal::displayAge() {
    std::cout << "Age: " << m_age << " years" << std::endl;
}
