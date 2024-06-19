#include <list>
#include <vector>
#include <string>
#include <functional>

class HashTable 
{
private:
    std::vector<std::list<std::pair<int, std::string>>> table;
    int total_elements;
    int hashFunction(int key);
public:
    HashTable(int size);
    void insertItem(int key, const std::string& value);
    void deleteItem(int key);
    std::string searchItem(int key);
    void displayHashTable();
};