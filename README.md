# Markov Chain Text Generator

A simple C++ program that generates random text using a Markov chain built from a sample text file.

## How it works

1. Reads words from `sample.txt`
2. Builds a hash table of bigrams (pairs of consecutive words)
3. For each bigram, stores possible next words (suffixes)
4. Takes an input of at least two words
5. Generates new words by looking up suffixes and picking random ones

## Usage

```bash
g++ -std=c++17 src/Markov.cpp src/hash.cpp -o markov
./markov
