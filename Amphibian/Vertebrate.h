// Vertebrate.h
#ifndef VERTEBRATE_H
#define VERTEBRATE_H

#include "Animal.h"
#include <string>

class Vertebrate : virtual public Animal {
protected:
    std::string m_backbone;
public:
    Vertebrate(const int&, const std::string&);
    void displayBackbone();
};

#endif // VERTEBRATE_H
