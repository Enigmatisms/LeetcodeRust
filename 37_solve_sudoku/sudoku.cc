#include <bitset>
#include <vector>
#include <iostream>

/**
 * 4ms (94.39%) run-time
 * 6.43MB (8.91%) memory
 */

class Solution {
using OccGrid = std::bitset<9>;
using Grids   = std::vector<OccGrid>;
using Board   = std::vector<std::vector<char>>;
public:
    // return the number of occupied spots
    uint8_t convert_occ_map(Board& board, Grids& occ_grids, int& start_i, int& start_j) const {
        uint8_t counter = 0;
        for (int i = 0; i < 9; i++) {
            int patch_i = i / 3;
            OccGrid& row_grid = occ_grids[i];
            std::vector<char>& board_row = board[i];
            for (int j = 0; j < 9; j++) {
                char char_v = board_row[j];
                if (char_v == '.') {
                    if (start_i < 0) {
                        start_i = i;
                        start_j = j;
                    }
                    continue;
                }
                int idx = int(char_v) - 49;
                int patch_id = 18 + patch_i * 3 + (j / 3);
                OccGrid &patch_grid = occ_grids[patch_id], &col_grid = occ_grids[j + 9];
                row_grid[idx] = 1;
                col_grid[idx] = 1;
                patch_grid[idx] = 1;
                counter ++;
            }
        }
        return 81 - counter;
    }

    void solveSudoku(Board& board) const {
        Grids occ_grids(27, OccGrid());
        int start_i = -1, start_j = -1;
        uint8_t num_occ = convert_occ_map(board, occ_grids, start_i, start_j);
        recursive_solve(occ_grids, board, num_occ, start_i, start_j);
    }

    bool recursive_solve(Grids& occ_grids, Board& board, uint8_t remain_num, int start_i = 0, int start_j = 0) const {
        if (remain_num == 0) {
            return true;
        }
        for (int i = start_i; i < 9; i++) {
            int patch_i = i / 3;
            OccGrid& row_grid = occ_grids[i];
            // when the row id get refreshed, we should set start_j to 0
            if (row_grid.all()) {           
                start_j = 0;
                continue;                   // row is full
            }
            std::vector<char>& board_row = board[i];
            for (int j = start_j; j < 9; j++) {
                if (board_row[j] != '.') continue;           // current place can not be set
                OccGrid& col_grid = occ_grids[j + 9];
                if (col_grid.all()) continue;                // column is full

                int patch_j = j / 3;
                OccGrid& patch_grid = occ_grids[18 + patch_i * 3 + patch_j];
                if (patch_grid.all()) {                     // patch is full, skip this patch
                    j = 2 + 3 * patch_j;
                    continue;
                }
                bool success = false;                       // if all the digit failed this test: something wrong with the previous settings
                for (uint8_t k = 0; k < 9; k++) {
                    if (row_grid[k] || col_grid[k] || patch_grid[k]) continue;      // occupied
                    row_grid[k] = 1;
                    col_grid[k] = 1;
                    patch_grid[k] = 1;
                    success = recursive_solve(occ_grids, board, remain_num - 1, i, j + 1);
                    if (!success) {
                        row_grid[k] = 0;
                        col_grid[k] = 0;
                        patch_grid[k] = 0;
                    } else {
                        board_row[j] = char(49 + k);
                        return true;
                    }
                } 
                if (!success) {
                    return false;
                }
            }
            start_j = 0;
        }
        return false;
    }
};

int main() {
    std::vector<std::vector<char>> inputs ={
        {'5','3','.','.','7','.','.','.','.'},
        {'6','.','.','1','9','5','.','.','.'},
        {'.','9','8','.','.','.','.','6','.'},
        {'8','.','.','.','6','.','.','.','3'},
        {'4','.','.','8','.','3','.','.','1'},
        {'7','.','.','.','2','.','.','.','6'},
        {'.','6','.','.','.','.','2','8','.'},
        {'.','.','.','4','1','9','.','.','5'},
        {'.','.','.','.','8','.','.','7','9'}
    };

    Solution sol;

    sol.solveSudoku(inputs);
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            printf("%c, ", inputs[i][j]);
        }
        printf("\n");
    }
}