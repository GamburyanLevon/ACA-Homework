#include <iostream>
#include <exception>

class A {
public:
    ~A() {
        try 
        {
            throw "exception from destructor";
        } 
        catch (const char* e) 
        {
            std::cout << "destructor: " << e << std::endl;
        }
    }
};

int main() {
    try 
    {
        A a;
    } 
    catch (const char* e) 
    {
        std::cerr << "main: " << e << std::endl;
    }

    return 0;
}
