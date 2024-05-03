#include <string>

class Carsinterface {
public:
    virtual std::string getModel() const = 0;
    virtual int getYear() const = 0;
    virtual double getPrice() const = 0;
    virtual void print() = 0;
};