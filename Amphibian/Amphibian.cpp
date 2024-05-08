#include "Amphibian.h"
#include <iostream>

Amphibian::Amphibian(const int& age, const std::string& backbone,const std::string& habitat)
    : Animal(age), Vertebrate(age, backbone), m_habitat(habitat) {}

void Amphibian::displayHabitat() {
    std::cout << "Habitat: " << m_habitat << std::endl;
}
