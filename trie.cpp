#include "trie.hpp"
using namespace std;

Trie::TrieNode::TrieNode()
{
    isEndOfWord = false;
    for (int i = 0; i < 26; ++i)
    {
        children[i] = nullptr;
    }
}

Trie::Trie()
{
    root = new TrieNode();
};

void Trie::insert(const std::string& word) {
    TrieNode* curr = root;
    for (char c : word) {
        if(isalpha(c) == 0) {
            return;
        }
        int index = toupper(c) - 'A';
        if (curr->children[index] == nullptr) {
            curr->children[index] = new TrieNode();
        }
        curr = curr->children[index];
    }
    curr->isEndOfWord = true;
}

bool Trie::search(const std::string& word) {
    TrieNode* curr = root;
    for (char c : word) {
        int index = c - 'A';
        if (curr->children[index] == nullptr) {
            return false;
        }
        curr = curr->children[index];
    }
    return curr->isEndOfWord;
}

bool Trie::startsWith(const std::string& prefix) {
    TrieNode* curr = root;
    for (char c : prefix) {
        int index = c - 'A';
        if (curr->children[index] == nullptr) {
            return false;
        }
        curr = curr->children[index];
    }
    return true;
}
