#include <string>
using namespace std;

class Trie
{
private:
    class TrieNode
    {
    public:
        bool isEndOfWord;
        TrieNode *children[26]; 

        TrieNode()
        {
            isEndOfWord = false;
            for (int i = 0; i < 26; ++i)
            {
                children[i] = nullptr;
            }
        }
    };
    TrieNode *root = nullptr;

public:
    Trie()
    {
        root = new TrieNode();
    };

    void insert(const std::string& word) {
        TrieNode* curr = root;
        for (char c : word) {
            int index = c - 'A';
            if (curr->children[index] == nullptr) {
                curr->children[index] = new TrieNode();
            }
            curr = curr->children[index];
        }
        curr->isEndOfWord = true;
    }

    bool search(const std::string& word) {
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

    bool startsWith(const std::string& prefix) {
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
};