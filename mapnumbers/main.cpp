#include <iostream>
#include <string>
#include <map>

std::string numberToString(int num)
{
    std::map<int, std::string> numToWords = 
    {
        {0, "zero"}, {1, "one"}, {2, "two"}, {3, "three"}, {4, "four"},
        {5, "five"}, {6, "six"}, {7, "seven"}, {8, "eight"}, {9, "nine"},
        {10, "ten"}, {11, "eleven"}, {12, "twelve"}, {13, "thirteen"},
        {14, "fourteen"}, {15, "fifteen"}, {16, "sixteen"}, {17, "seventeen"},
        {18, "eighteen"}, {19, "nineteen"}, {20, "twenty"}, {30, "thirty"},
        {40, "forty"}, {50, "fifty"}, {60, "sixty"}, {70, "seventy"},
        {80, "eighty"}, {90, "ninety"}, {100, "hundred"}, {1000, "thousand"}
    };

    if (num < 100) 
    {
        int tens = num / 10 * 10;
        int units = num % 10;
        return numToWords[tens] + "-" + numToWords[units];
    }

    if (num < 1000) 
    {
        int hundreds = num / 100;
        int remainder = num % 100;
        if (remainder == 0) 
        {
            return numToWords[hundreds] + " " + numToWords[100];
        } 
        else 
        {
            return numToWords[hundreds] + " " + numToWords[100] + " and " + numberToString(remainder);
        }
    }

    if (num == 1000) 
    {
        return "one thousand";
    }

    return "Invalid number";
}

int main() 
{
    int num;
    std::cin >> num;
    
    if (num < 0 || num > 1000) 
    {
        std::cout << "Invalid number" << std::endl;
    } 
    else 
    {
        std::cout << numberToString(num) << std::endl;
    }
    
    return 0;
}
