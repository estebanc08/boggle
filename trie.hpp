#ifndef TRIE_HPP
#define TRIE_HPP

#include <string>

using namespace std;

class Trie {
public:
    Trie();
    void insert(const string &word);
    bool search(const string &word);
    bool startsWith(const string &prefix);

private:
   class TrieNode
    {
    public:
        bool isEndOfWord;
        TrieNode *children[26]; 

        TrieNode();
    };
    TrieNode *root = nullptr;
};

#endif