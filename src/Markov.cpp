#include "include/hash.hpp"
#include <iostream>
#include<fstream>
#include <bits/stdc++.h>




int main()
{
    std::ifstream file("sample.txt");
    std::vector<std::string> Text_vect ;
    std::string word ;
    while(file>>word)
    {
        Text_vect.push_back(word);
    }
    
    /* Print the text vector */
    std::cout << "Words loaded: " << Text_vect.size() << std::endl;
    for(size_t i = 0; i < Text_vect.size(); i++)
    {
        std::cout << Text_vect[i] << " ";
    }
    std::cout << std::endl;
    
    /* defining the hashTable*/
    HashTable dict(Text_vect.size());
    /* sliding window to iterates on bigrams*/

    for (size_t i = 0; i + 1 < Text_vect.size(); ++i) {
        std::string bigram = Text_vect[i] + " " + Text_vect[i + 1];

        // build up to 3-word suffix safely
        std::string suffixs;
    if (i + 2 < Text_vect.size()) suffixs += Text_vect[i + 2];
        
        suffixs += " ";
    if (i + 3 < Text_vect.size()) suffixs += Text_vect[i + 3];
        
        suffixs += " ";
    if (i + 4 < Text_vect.size()) suffixs += Text_vect[i + 4];

        dict.Insert(bigram, suffixs);
    }
    dict.Print();
    /* getting input text*/
    std::cout << "------------------------------------ MARKOV CHAIN TEXT GENERATOR ---------------------------------------------------- \n" ;
    std::cout << "input text (at least two words): \n";
    const int output_length = 5;
    std:: string input_text ;
    std::getline(std::cin, input_text);
    int c = 0 ;
    /* string to vect*/
    std::vector<std::string> input_vect ;
    std::stringstream ss(input_text);
    
   
    while (ss>>word)
    {
        input_vect.push_back(word);
    }
    
    while( c < output_length)
    {
        auto bigram  = input_vect[input_vect.size()-2] + " " + input_vect[input_vect.size()-1];
        auto suffixs = dict.Search(bigram);
        
        // Check if bigram not found in dictionary
        if(suffixs.empty())
        {
            std::cout << "\nKey not found: " << bigram << "\n";
            std::cout << "Generated text: ";
            for(size_t i = 0; i < input_vect.size(); i++)
            {
                std::cout << input_vect[i] << " ";
            }
            std::cout << "\n";
            break;
        }
        
        std::vector<std::string> suffixs_vec ;
        std::stringstream suffix_ss(suffixs);
        while (suffix_ss>>word)
        {
            suffixs_vec.push_back(word);
        }
        
        if(suffixs_vec.empty())
        {
            std::cout << "\nNo valid suffix found for: " << bigram << "\n";
            std::cout << "Generated text: ";
            for(size_t i = 0; i < input_vect.size(); i++)
            {
                std::cout << input_vect[i] << " ";
            }
            std::cout << "\n";
            break;
        }
        
        int random_idx = rand() % suffixs_vec.size();
        std::cout << "possible suffixs for "<<  bigram<< " is " << suffixs << "\n" ;
        input_vect.push_back(suffixs_vec[random_idx]);

        c++;
    }
    
   


}