#include <iostream>
#include "include/hash.hpp"
#include <cmath>
#include <assert.h>


int HashTable::HashFunction(std::string s , int N)
{
    const int  p  = 5;
    const int m = pow(2,9);
    int idx = 0 ;
    for (int i = 0 ; i < N  ; i++)
    {
        idx = idx + s[i]*pow(p,i);
    }
    return idx % m ;


}
void HashTable::Insert(std::string key,std::string Value )
{
    std::cout << capacity ;
    int Hash_idx = HashFunction(key,key.length()) % capacity;
    /* check if the bucket is empty or no */
    std::pair Key_Value = (*Buckets)[Hash_idx];
    if(Key_Value.first == "")
    {
        std::pair<std::string,std::string> key_value ;
        key_value.first = key ;
        key_value.second =Value ;
       (*Buckets)[Hash_idx] = key_value;

    }
    else if (Key_Value.first == key)
    {
        std:: cout << "Key already existing " ;
    }
    else
    {
        /*rehash until find an empty place */
        int is_hashed = 0 ;
        int c = 1    ;
        while(is_hashed == 0 and c < capacity)
        {
             int rehash_idx = int((Hash_idx + c)) % capacity;
             std::pair Key_Value = (*Buckets)[rehash_idx];
             if (Key_Value.first == "")
             {
                is_hashed = 1 ;
                std::pair<std::string,std::string> key_value ;
                key_value.first = key ;
                key_value.second =Value ;
                 (*Buckets)[rehash_idx] = key_value;
                

             }
             c++ ;
        }
        if (!is_hashed) std::cout << "Table full\n";

    }
  
    
}
HashTable::HashTable(int cap){
        capacity = cap ;
        Buckets = new std::vector<std::pair<std::string,std::string>>(capacity);
    }

std::string HashTable::Search(std::string Key){
int Hash_idx = HashFunction(Key,Key.length()) % capacity;
auto Key_Value = (*Buckets)[Hash_idx];
if (Key_Value.first  == "")
{
    std::cout << "Key not existing  \n" ;
}
else{
    
     if (Key_Value.first ==  Key)
     {
         std::cout << "Key found  \n" ;
         return Key_Value.second; 
     }
     else
     {
        int is_hashed = 0 ;
        int c = 1    ;
         while(is_hashed == 0 and c < capacity)
        {
             int rehash_idx = int((Hash_idx + c)) % capacity;
             std::pair Key_Value = (*Buckets)[rehash_idx];
             std::cout << rehash_idx << " \n";
             if (Key_Value.first == Key)
             {
                std::cout << "Key found  \n" ;
                

             }
             c++ ;
        }
         
         std::cout << "Key not found  \n" ;
     }
}
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