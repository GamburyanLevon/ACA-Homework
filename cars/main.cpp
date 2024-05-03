#include "car.h"
#include "crossover.h"
#include "electricSedan.h"
#include "hyperCar.h"
#include "jeep.h"
#include "sedan.h"
#include "sportsCar.h"

int main() 
{
    electircSedan Tesla("Tesla model X", 2020, 670, 40000, 4, 500);
    Crossover Palisade("Hyudani Palisade", 2024, 291, 36000, "Crossover", "4 wheel drive");
    HyperCar Koenigsegg("Koenigsegg Jesko", 2021, 1600, 3000000, 532, 2.5, "Adjustable pedals and steering column");


    Tesla.print();
    Palisade.print();
    Koenigsegg.print();

    return 0;
}