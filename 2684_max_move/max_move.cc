#include <iostream>
#include <vector>
#include <algorithm>

/**
 * 动态规划问题，并且可以用 O(n) 额外存储解决
 * 注意审题：只要路断了，就不能再继续了
 * runtime: 92.41%
 * memory:  69.62%
 */
class Solution {
public:
    int maxMoves(std::vector<std::vector<int>>& grid) {
        int num_col = grid[0].size(), num_row = grid.size(), max_move = 0;
        std::vector<int> moves(num_row, 0);
        for (int col = 1; col < num_col; col++) {
            std::vector<int> new_moves(num_row, 0);
            bool find_path = false;
            for (int row = 0; row < num_row; row++) {
                int move = 0, cur_v = grid[row][col];
                if (row && cur_v > grid[row - 1][col - 1]) 
                    move = moves[row - 1] + 1;
                if (cur_v > grid[row][col - 1]) 
                    move = std::max(move, moves[row] + 1);
                if (row + 1 < num_row && cur_v > grid[row + 1][col - 1]) 
                    move = std::max(move, moves[row + 1] + 1);
                if (move) {
                    find_path = true;
                    max_move = std::max(move, max_move);
                    new_moves[row] = move;
                } else {
                    new_moves[row] = -1;
                }
            }
            if (!find_path) return max_move;
            moves = std::move(new_moves);
        }
        return max_move;
    }
};

int main(int argc, char** argv) {
    Solution sol;

    return 0;
}