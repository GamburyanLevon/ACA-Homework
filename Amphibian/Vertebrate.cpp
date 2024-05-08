#include "Vertebrate.h"
#include <iostream>

Vertebrate::Vertebrate(const int& age, const std::string& backbone) : Animal(age), m_backbone(backbone) {}

void Vertebrate::displayBackbone() {
    std::cout << "Backbone: " << m_backbone << std::endl;
}
