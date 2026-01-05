#include <vector>
#include <string>
#ifndef HASH
#define HASH

class HashTable
{
 public:
    int capacity ;
    HashTable(int cap);
    std::vector<std::string> Keys ;
    std::vector<std::string> Values ;
    size_t HashFunction(const std::string& s);
    std::vector<std::pair<std::string,std::string>> * Buckets ;
    void Insert(const std::string& key, const std::string& values);
    std::string Search(const std::string& key);
    void Print();
};



#endif 