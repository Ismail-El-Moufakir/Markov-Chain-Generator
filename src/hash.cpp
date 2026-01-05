#include <iostream>
#include "include/hash.hpp"
#include <cmath>
#include <assert.h>


// In hash.hpp/cpp
size_t HashTable::HashFunction( const std::string& s)  {
   
    const size_t P = 1315423911u; 
    size_t h = 0;
    for (unsigned char c : s) {
        h = h * 131u + c; 
    }
    return h % capacity;   
}

void HashTable::Insert(const std::string& Key, const std::string& Value)
{

    for(int step = 0 ; step < capacity; step ++)
    {
        size_t hash_idx = (HashFunction(Key) + step)%capacity ;
        auto kv =  (*Buckets)[hash_idx] ;
        if(kv.first == "")
        {
            std::pair<std::string,std::string> kv ;
            kv.first =Key ;
            kv.second = Value ;
            (*Buckets)[hash_idx] = kv ;
            return ;

        }
        else if(kv.first == Key)
        {
            std:: cout << "Key already existing \n" ;
            return ;
        }


    }
    std::cout<< "Hash Table Full \n";
    return ;
    
}
HashTable::HashTable(int cap){
        capacity = cap ;
        Buckets = new std::vector<std::pair<std::string,std::string>>(capacity);
    }

std::string HashTable::Search(const std::string& key) {
    size_t i = HashFunction(key);
    for (size_t step = 0; step < capacity; ++step) {
        size_t idx = (i + step) % capacity;
        const auto& kv = (*Buckets)[idx];
        if (kv.first.empty()) {
            std::cout << "Key not found\n";
            return "";
        }
        if (kv.first == key) {
            std::cout << "Key found\n";
            return kv.second;
        }
    }
    std::cout << "Key not found\n";
    return "";
}


void HashTable::Print()
{
    std::cout << "\n--- HashTable Contents ---\n";
    for (int i = 0; i < capacity; i++) {
        std::string key = (*Buckets)[i].first;
        std::string value = (*Buckets)[i].second;
        if (key != "") {
            std::cout << "Index " << i << ": [" << key << " -> " << value << "]\n";
        }
    }
    std::cout << "--- End Contents ---\n\n";
}
/*

int main()
{
    std::cout << "=== HashTable Robustness Test ===\n\n";
    
    HashTable hash(20);
    
    // Test 1: Insert and Search
    std::cout << "Test 1: Insert and Search\n";
    std::cout << "Inserting ('apple', 'red')...\n";
    hash.Insert("apple", "red");
    std::cout << "Searching for 'apple'...\n";
    hash.Search("apple");
    hash.Print();
    
    // Test 2: Multiple inserts
    std::cout << "Test 2: Multiple Inserts\n";
    hash.Insert("banana", "yellow");
    hash.Insert("grape", "purple");
    hash.Insert("lemon", "yellow");
    std::cout << "Inserted 3 more items\n";
    hash.Print();
    
    // Test 3: Search for existing keys
    std::cout << "Test 3: Search for Existing Keys\n";
    hash.Search("banana");
    hash.Search("grape");
    hash.Search("lemon");
    hash.Print();
    
    // Test 4: Search for non-existing key
    std::cout << "Test 4: Search for Non-Existing Key\n";
    hash.Search("orange");
    hash.Print();
    
    // Test 5: Duplicate key insertion
    std::cout << "Test 5: Attempt Duplicate Key Insertion\n";
    hash.Insert("apple", "green");
    hash.Print();
    
    // Test 6: Hash function consistency
    std::cout << "Test 6: Hash Function Consistency\n";
    std::string testStr = "test";
    int hash1 = hash.HashFunction(testStr, testStr.length());
    int hash2 = hash.HashFunction(testStr, testStr.length());
    std::cout << "Hash of 'test' (call 1): " << hash1 << "\n";
    std::cout << "Hash of 'test' (call 2): " << hash2 << "\n";
    std::cout << "Hashes are " << (hash1 == hash2 ? "consistent" : "inconsistent") << "\n";
    hash.Print();
    
    // Test 7: Print hash table contents
    std::cout << "Test 7: Hash Table Contents\n";
    hash.Print();
    
    std::cout << "=== Test Complete ===\n";
    
    return 0;
}
 */