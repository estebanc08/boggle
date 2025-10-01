#include "boggle.hpp"

int main() {
    Trie wordList = readWords();
    vector<vector<char>> board = generateBoard();
    printBoard(board);

    map<int, set<string>> words;
    for(int y = 0; y < DIMENSION; y++){
        for(int x = 0; x < DIMENSION; x++){
            solveBoard(board, words, "", wordList, x, y);
        }
    }

     for (auto it = words.rbegin(); it != words.rend(); ++it) {
        if(it->first >= 5){
            cout << it->first << endl;
            for(const auto& w : it->second){
                cout << w << endl;
            }   
        }
    }
}

void solveBoard(vector<vector<char>>& board, map<int, set<string>>& words, string word, Trie& list, int x, int y){
    char curr = board[y][x];
    word += curr;
    
    if(list.search(word)){
        words[word.length()].insert(word);
    }
    
    board[y][x] = '0';
    
    for (const auto& dir : directions) {
        int newX = x + dir.second;
        int newY = y + dir.first;

        if (newX >= 0 && newX < DIMENSION && newY >= 0 && newY < DIMENSION && board[newY][newX] != '0' && list.startsWith(word)) {
            solveBoard(board, words, word, list, newX, newY);
        }
    }

    word.pop_back();
    board[y][x] = curr;
}

Trie readWords(){
    ifstream infile;
    infile.open("word_list.txt");

    if (!infile.is_open()) {
        cerr << "Error: Could not open the file.\n";
        return {};
    }

    Trie trie;
    string line;
    while (getline(infile, line)) {
        trie.insert(line);
    }
    infile.close();
    return trie;
}

vector<vector<char>> generateBoard() {
    vector<vector<char>> board(DIMENSION, vector<char>(DIMENSION));
    random_device rd;
    mt19937 gen(rd());
    int size = DIMENSION * DIMENSION;
    vector<int> die(size);
    
    for(int i = 0; i < size; i++){
        die[i] = i;
    }
    
    for (int i = 0; i < DIMENSION; ++i) {
        for (int j = 0; j < DIMENSION; ++j) {
            uniform_int_distribution<> dis(0, size);
            int val = dis(gen);
            uniform_int_distribution<> sides(0, 5);
            int side = sides(gen);
            board[i][j] = dice25[die[val]][side];
            swap(die[val], die[--size]);
        }
    }
    return board;
}

void printBoard(const vector<vector<char>>& board) {
    printf("\n");
    for (const auto& row : board) {
        for (const auto& ch : row) {
            cout << ch << ' ';
        }
        cout << endl;
    }
    printf("\n");
}


