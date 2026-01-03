#include <vector>

#ifndef HASH
#define HASH

class HashTable
{
 public:
    int capacity ;
    HashTable(int cap);
    std::vector<std::string> Keys ;
    std::vector<std::string> Values ;
    int HashFunction(std:: string s , int N);
    std::vector<std::pair<std::string,std::string>> * Buckets ;
    void Insert(std::string key , std::string values);
    std::string Search(std::string key);
    void Print();
};




#endif 