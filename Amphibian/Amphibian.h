// Amphibian.h
#ifndef AMPHIBIAN_H
#define AMPHIBIAN_H

#include "Animal.h"
#include "Vertebrate.h"
#include <string>

class Amphibian : virtual public Animal, virtual public Vertebrate {
protected:
    std::string m_habitat;

public:
    Amphibian(const int&, const std::string&,const std::string&);
    void displayHabitat();
};

#endif // AMPHIBIAN_H
