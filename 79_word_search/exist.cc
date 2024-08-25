#include<vector>
#include<iostream>

// 我有个问题：为什么我的代码总能那么长... 虽然这里确实是不必要的，我做了循环展开以追求速度
// 一顿 coding 猛如虎，结果输出 TLE，栈太深了（而且不应该用 unordered_set），如何进行剪枝？
// 不不... TLE 只是因为使用了 unordered_set
// runtime: 80.61%
// memory:  15.94%
class Solution {
using Row   = std::vector<char>;
using Board = std::vector<std::vector<char>>;
using Grid  = std::vector<std::vector<bool>>;
public:
    bool exist(const Board& board, const std::string& word) const {
        int rows = board.size(), cols = board.front().size();
        if (word.length() > rows * cols) return false;
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (board[i][j] == word.front()) {
                    Grid accessed(rows, std::vector<bool>(cols, false));
                    accessed[i][j] = true;
                    bool flag = recursive_search(board, word, accessed, 1, rows, cols, i, j);
                    if (flag) return true;
                }
            }
        }
        return false;
    }

    static bool recursive_search(
        const Board& board, const std::string& word, Grid& accessed,
        int ptr, int rows, int cols, int cur_i, int cur_j
    ) {
        if (ptr == word.length()) return true;
        char word_ch = word[ptr++];   
        bool flag = false;
        if (cur_i + 1 < rows) {
            auto access_flag = accessed[cur_i + 1][cur_j];
            if (access_flag == false && word_ch == board[cur_i + 1][cur_j]) {
                access_flag = true;
                flag = recursive_search(board, word, accessed, ptr, rows, cols, cur_i + 1, cur_j);
                access_flag = false;
            }
        }
        if (flag) return true;
        if (cur_j + 1 < cols) {
            auto access_flag = accessed[cur_i][cur_j + 1];
            if (access_flag == false && word_ch == board[cur_i][cur_j + 1]) {
                access_flag = true;
                flag = recursive_search(board, word, accessed, ptr, rows, cols, cur_i, cur_j + 1);
                access_flag = false;
            }
        }
        if (flag) return true;
        if (cur_i - 1 >= 0) {
            auto access_flag = accessed[cur_i - 1][cur_j];
            if (access_flag == false && word_ch == board[cur_i - 1][cur_j]) {
                access_flag = true;
                flag = recursive_search(board, word, accessed, ptr, rows, cols, cur_i - 1, cur_j);
                access_flag = false;
            }
        }
        if (flag) return true;
        if (cur_j - 1 >= 0) {
            auto access_flag = accessed[cur_i][cur_j - 1];
            if (access_flag == false && word_ch == board[cur_i][cur_j - 1]) {
                access_flag = true;
                flag = recursive_search(board, word, accessed, ptr, rows, cols, cur_i, cur_j - 1);
                access_flag = false;
            }
        }
        return flag;
    }
};


int main() {
    Solution sol;
    std::vector<std::vector<char>> board = {{'A','B','C','E'},{'S','F','C','S'},{'A','D','E','E'}};
    std::vector<std::string> test_words = {"ABCCED", "SEE", "ABCB"};
    for (auto word: test_words) {
        std::cout << sol.exist(board, word) << std::endl;
    }
    return 0;
}