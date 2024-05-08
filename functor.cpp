#include <iostream>

class A {
public:
    int operator()(int n) const {
        int result = 1;
        for (int i = 2; i <= n; ++i) {
            result *= i;
        }
        return result;
    }
};

void factorial(const A& functor, const int& number) {
    std::cout << "Factorial of " << number << " is: " << functor(number) << std::endl;
}

int main() {
    A a;

    int number = 5;
    factorial(a, number);

    return 0;
}
