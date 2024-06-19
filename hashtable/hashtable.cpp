#include "hashtable.h"
#include <iostream>

int HashTable::hashFunction(int key) 
{
    return key % table.size();
}

HashTable::HashTable(int size)
{
    table.resize(size);
    total_elements = 0;
}

void HashTable::insertItem(int key, const std::string &value)
{
    int hash_index = hashFunction(key);
    for (auto &pair : table[hash_index])
    {
        if (pair.first == key)
        {
            pair.second = value;
            return;
        }
    }
    table[hash_index].push_front(std::make_pair(key, value));
    total_elements++;
}

void HashTable::deleteItem(int key)
{
    int hash_index = hashFunction(key);
    auto &chain = table[hash_index];
    for (auto it = chain.begin(); it != chain.end(); ++it)
    {
        if (it->first == key)
        {
            chain.erase(it);
            total_elements--;
            return;
        }
    }
    std::cout << "Key not found!" << std::endl;
}

std::string HashTable::searchItem(int key)
{
    int hash_index = hashFunction(key);
    for (const auto &pair : table[hash_index])
    {
        if (pair.first == key)
        {
            return pair.second;
        }
    }
    return "Key not found!";
}

void HashTable::displayHashTable()
{
    for (int i = 0; i < table.size(); ++i)
    {
        std::cout << "Index " << i << ": ";
        for (const auto &pair : table[i])
        {
            std::cout << "(" << pair.first << ", " << pair.second << ") ";
        }
        std::cout << std::endl;
    }
}