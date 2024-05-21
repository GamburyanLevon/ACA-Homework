#include <iostream>
#include <fstream>
#include <string>

union Data 
{
    int i;
    float f;
    char s[50];

    Data() {}
    ~Data() {}
};

enum DataType 
{
    INTEGER,
    FLOAT,
    STRING
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

    size_t pos = 0;
    if (str[pos] == '-') 
    {
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

bool isFloat(const std::string& str) {
    if (str.empty())
    {
        return false;
    }

    bool hasDecimal = false;
    size_t pos = 0;

    if (str[pos] == '-') 
    {
        ++pos;
    }

    while (pos < str.size()) 
    {
        if (str[pos] == ',') 
        {
            if (hasDecimal) 
            {
                return false;
            }
            hasDecimal = true;
        } 
        else if (!isDigit(str[pos])) 
        {
            return false;
        }
        ++pos;
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

        Data data;
        DataType type;

        if (isInteger(line)) 
        {
            data.i = std::stoi(line);
            type = INTEGER;
        } 
        else if (isFloat(line)) 
        {
            data.f = std::stof(line);
            type = FLOAT;
        } 
        else 
        {
            std::strncpy(data.s, line.c_str(), sizeof(data.s) - 1);
            data.s[sizeof(data.s) - 1] = '\0';
            type = STRING;
        }

        switch (type) 
        {
            case INTEGER:
                std::cout << "INTEGER: " << data.i << std::endl;
                break;
            case FLOAT:
                std::cout << "FLOAT: " << data.f << std::endl;
                break;
            case STRING:
                std::cout << "STRING: " << data.s << std::endl;
                break;
        }
    }

    file.close();
    return 0;
}
