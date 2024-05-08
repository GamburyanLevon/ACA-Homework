#include "Amphibian.h"
#include <iostream>

int main() {
    Amphibian frog(2, "Vertebral column", "Aquatic");

    frog.displayAge();
    frog.displayBackbone();
    frog.displayHabitat();

    return 0;
}
