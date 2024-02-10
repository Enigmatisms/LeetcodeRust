#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>

using namespace std;

/**
 * 
 * runtime: 74.51%
 * memory:  21.06%
 */
class Solution {
private:
    uint16_t rows, cols;
public:
    void flood_fill(vector<vector<char>>& board, uint16_t ri, uint16_t ci) const {
        if (board[ri][ci] == 0) return;
        board[ri][ci] = 0;
        std::vector<std::pair<uint16_t, uint16_t>> stack = {{ri, ci}};
        while (!stack.empty()) {
            uint16_t row = stack.back().first, col = stack.back().second;
            stack.pop_back();
            if (row) {
                if (board[row - 1][col] == 'O') {
                    board[row - 1][col] = 0;
                    stack.emplace_back(row - 1, col);
                }
            }
            if (row + 1 < rows) {
                if (board[row + 1][col] == 'O') {
                    board[row + 1][col] = 0;
                    stack.emplace_back(row + 1, col);
                }
            }
            if (col) {
                if (board[row][col - 1] == 'O') {
                    board[row][col - 1] = 0;
                    stack.emplace_back(row, col - 1);
                }
            }
            if (col + 1 < cols) {
                if (board[row][col + 1] == 'O') {
                    board[row][col + 1] = 0;
                    stack.emplace_back(row, col + 1);
                }
            }
        }
    }

    void solve(vector<vector<char>>& board) {
        rows = board.size();
        cols = board.front().size();
        if (rows <= 2 || cols <= 2) return; 
        for (uint16_t i = 0; i < cols; i++) {
            if (board[0][i] == 'O')
                flood_fill(board, 0, i);
            if (board[rows - 1][i] == 'O')
                flood_fill(board, rows - 1, i);
        }
        for (uint16_t i = 0; i < rows; i++) {
            if (board[i][0] == 'O')
                flood_fill(board, i, 0);
            if (board[i][cols - 1] == 'O')
                flood_fill(board, i, cols - 1);
        }
        for (uint16_t i = 0; i < rows; i++) {
            std::vector<char>& char_vec = board[i];
            for (uint16_t j = 0; j < cols; j++) {
                char& current = char_vec[j];
                if (current == 'O')
                    current = 'X';
                else if (current == 0)
                    current = 'O';
            }
        }
    }
};

int main(int argc, char** argv) {
    Solution sol;

    return 0;
}