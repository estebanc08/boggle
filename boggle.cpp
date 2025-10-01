#include "boggle.hpp"

int main(int argc, char* argv[]) {
    Trie wordList = readWords();
    vector<vector<char>> board = generateBoard();
    printBoard(board);
    vector<string> words;
    for(int y = 0; y < DIMENSION; y++){
        for(int x = 0; x < DIMENSION; x++){
            solveBoard(board, words, "", wordList, x, y);
        }
    }
    for(string& word : words){
        cout << word << endl;
    }
}

void solveBoard(vector<vector<char>>& board, vector<string>& words, string word, Trie& list, int x, int y){
    char curr = board[y][x];
    word += curr;
    if(list.search(word)){
        words.push_back(word);
    }
    board[y][x] = '0';
    // ONE DIRECTION 
    if(y - 1 >= 0 && board[y-1][x] != '0' && list.startsWith(word)){
        solveBoard(board, words, word, list, x, y-1);
    }
    if(y + 1 < DIMENSION && board[y+1][x] != '0' && list.startsWith(word)){
        solveBoard(board, words, word, list, x, y+1);
    }
    if(x - 1 >= 0 && board[y][x-1] != '0' && list.startsWith(word)){
        solveBoard(board, words, word, list, x-1, y);
    }
    if(x + 1 < DIMENSION && board[y][x+1] != '0' && list.startsWith(word)){
        solveBoard(board, words, word, list, x+1, y);
    }
     
    // DIAGONALS
    // UP AND LEFT
    if(y - 1 >= 0 && x - 1 >= 0 && board[y-1][x-1] != '0' && list.startsWith(word)){
        solveBoard(board, words, word, list, x-1, y-1);
    }
    // UP AND RIGHT
    if(y - 1 >= 0 && x + 1 < DIMENSION && board[y-1][x+1] != '0' && list.startsWith(word)){
        solveBoard(board, words, word, list, x+1, y-1);
    }
    // DOWN AND LEFT
    if(y + 1 < DIMENSION && x - 1 >= 0 && board[y+1][x-1] != '0' && list.startsWith(word)){
        solveBoard(board, words, word, list, x-1, y+1);
    }
    // DOWN AND RIGHT
    if(y + 1 < DIMENSION && x + 1 < DIMENSION && board[y+1][x+1] != '0' && list.startsWith(word)){
        solveBoard(board, words, word, list, x+1, y+1);
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
            swap(die[val], die[size]);
            size--;
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



