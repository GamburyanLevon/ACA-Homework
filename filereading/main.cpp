#include <iostream>
#include <fstream>
#include <string>

enum Type 
{
    INTEGER, FLOAT, STRING 
};

union Value 
{
    int i;
    float f;
    char s[50]; 
}; 

struct Data {
    Type type;
    Value value;

    Data(int val) {
        type = INTEGER;
        value.i = val;
    }

    Data(float val) 
    {
        type = FLOAT;
        value.f = val;
    }

    Data(const std::string& val) 
    {
        type = STRING;
        std::strncpy(value.s, val.c_str(), sizeof(value.s));
        value.s[sizeof(value.s) - 1] = '\0';  
    }
};


bool isDigit(char c) 
{
    return (c >= '0' && c <= '9');
}

bool isInteger(const std::string& str) 
{
    if (str.empty())
    {      
        return false;
    }

    int pos = 0;
    bool negative = false;

    if (str[pos] == '-') 
    {
        negative = true;
        ++pos;
    }

    if (pos == str.size()) 
    {
        return false;
    }

    while (pos < str.size()) 
    {
        if (!isDigit(str[pos])) 
        {
            return false;
        }
        ++pos;
    }

    return true;
}

bool isFloat(const std::string& str) 
{
    if (str.empty()) return false;

    bool hasDecimal = false; 

    for (char c : str) 
    {
        if (c == ',') 
        {
            hasDecimal = true;
        } 
        else if (!isDigit(c) && c != '-') 
        {
            return false;
        }
    }

    return hasDecimal;
}

int main() {
    std::ifstream file("data.txt");
    if (!file) 
    {
        std::cout << "Unable to open file" << std::endl;
        return 1;
    }

    std::string line;
    while (std::getline(file, line)) 
    {
        line.erase(0, line.find_first_not_of(" \t\n\r"));
        line.erase(line.find_last_not_of(" \t\n\r") + 1);

        if (isInteger(line)) 
        {
            std::cout << "INTEGER " << std::endl;
        } 
        else if (isFloat(line)) 
        {
            std::cout << "FLOAT" << std::endl;
        }
        else 
        {
            std::cout << "STRING" << std::endl;
        }
    }

    file.close();
    return 0;
}
