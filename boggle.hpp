#include <vector>
#include <iostream>
#include <random>
#include <algorithm>
#include <fstream>
#include "trie.cpp"
#define DIMENSION 5

using namespace std;


void solveBoard(vector<vector<char>>& board, vector<string>& words, string word, Trie& list, int x = 0, int y = 0);

vector<vector<char>> generateBoard();

Trie readWords();

void printBoard(const vector<vector<char>>& board);


vector<vector<char>> dice25 = {
    {'A','A','A','F','R','S'},
    {'A','A','E','E','E','E'},
    {'A','A','F','I','R','S'},
    {'A','D','E','N','N','N'},
    {'A','E','E','E','E','M'},
    {'A','E','E','G','M','U'},
    {'A','E','G','M','N','N'},
    {'A','F','I','R','S','Y'},
    {'B','J','K','Q','X','Z'},
    {'C','C','N','S','T','W'},
    {'C','E','I','I','L','T'},
    {'C','E','I','L','P','T'},
    {'C','E','I','P','S','T'},
    {'D','H','H','N','O','T'},
    {'D','H','H','L','O','R'},
    {'D','H','L','N','O','R'},
    {'D','D','L','N','O','R'},
    {'E','I','I','I','T','T'},
    {'E','M','O','T','T','T'},
    {'E','N','S','S','S','U'},
    {'F','I','P','R','S','Y'},
    {'G','O','R','R','V','W'},
    {'H','I','P','R','R','Y'},
    {'N','O','O','T','U','W'},
    {'O','O','O','T','T','U'}
};