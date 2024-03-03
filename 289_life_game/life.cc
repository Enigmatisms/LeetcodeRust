#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <unordered_map>
#include <unordered_set>

using namespace std;

/**
 * 原地操作是可以的，用位运算
 * runtime: 100.00%
 * memory:  30.51%
 */
class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        int rows = static_cast<int>(board.size()), cols = static_cast<int>(board[0].size());
        std::vector<std::vector<int>> updated(rows, std::vector<int>(cols, 0));
        for (int row = 0; row < rows; row ++) {
            for (int col = 0; col < cols; col++) {
                int cnt = 0;
                for (int i = -1; i < 2; i++) {
                    int cur_row = row + i;
                    if (cur_row < 0 || cur_row >= rows) continue;
                    for (int j = - 1; j < 2; j++) {
                        if (!i && !j) continue;
                        int cur_col = col + j;
                        if (cur_col < 0 || cur_col >= cols) continue;
                        cnt += board[cur_row][cur_col];
                        if (cnt > 3) break;
                    }
                }
                if (cnt == 3)
                    updated[row][col] = 1;
                else if (cnt == 2)
                    updated[row][col] = board[row][col];
            }
        }
        board = std::move(updated);
    }

    // O(1) memory: 52.30%
    void gameOfLife_inplace(vector<vector<int>>& board) {
        int rows = static_cast<int>(board.size()), cols = static_cast<int>(board[0].size());
        for (int row = 0; row < rows; row ++) {
            for (int col = 0; col < cols; col++) {
                int cnt = 0;
                for (int i = -1; i < 2; i++) {
                    int cur_row = row + i;
                    if (cur_row < 0 || cur_row >= rows) continue;
                    for (int j = - 1; j < 2; j++) {
                        if (!i && !j) continue;
                        int cur_col = col + j;
                        if (cur_col < 0 || cur_col >= cols) continue;
                        cnt += (board[cur_row][cur_col] & 1);
                        if (cnt > 3) break;
                    }
                }
                if (cnt == 3)
                    board[row][col] |= 0x02;
                else if (cnt == 2)
                    board[row][col] |= (board[row][col] << 1);
            }
        }
        for (auto& row: board) {
            for (auto& val: row) {
                val >>= 1;
            }
        }
    }
};

int main(int argc, char** argv) {
    Solution sol;

    return 0;
}