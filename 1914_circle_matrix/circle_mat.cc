#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/**
 * 
 * runtime: 54.76%
 * memory:  33.33%
 * 
 * 
 *  
 */
class Solution {
public:
    vector<vector<int>> rotateGrid(vector<vector<int>>& grid, int k) {
        recursive_process(grid, k, 0, grid.size(), grid[0].size());
        return grid;
    }

    void recursive_process(vector<vector<int>>& grid, int k, int shrink, int rows, int cols) {
        int s_col = shrink, e_col = cols - shrink, e_row = rows - shrink;
        int diff_col = e_col - shrink, diff_row = e_row - shrink, num_elem = diff_col * diff_row;
        bool can_recurse = diff_col > 2 && diff_row > 2;
        if (can_recurse)
            num_elem -= (diff_col - 2) * (diff_row - 2);
        int cur_k = k % num_elem;
        if (cur_k) {
            int swp_r = s_col, swp_c = s_col, swp_dr = 1, swp_dc = 0;
            std::vector<int> saved;
            for (int i = 0; i < num_elem; i++) {
                saved.push_back(grid[swp_r][swp_c]);
                move_next(swp_r, swp_c, swp_dr, swp_dc, s_col, e_col, e_row);
            }
            swp_r = s_col; swp_c = s_col; swp_dr = 1; swp_dc = 0;
            for (int i = 0; i < cur_k; i++)
                move_next(swp_r, swp_c, swp_dr, swp_dc, s_col, e_col, e_row);
            for (int i = 0; i < num_elem; i++) {
                grid[swp_r][swp_c] = saved[i];
                move_next(swp_r, swp_c, swp_dr, swp_dc, s_col, e_col, e_row);
            }
        }
        if (can_recurse)
            recursive_process(grid, k, shrink + 1, rows, cols);
    }

    void move_next(int& pr, int& pc, int& dr, int& dc, int s_col, int e_col, int e_row) {
        if (pr + 1 == e_row) {
            if (pc == s_col) {
                std::swap(dr, dc);
            } else if (pc + 1 == e_col) {
                dc = 0;
                dr = -1;
            }
        } else if (pr == s_col) {
            if (pc == s_col) {
                dr = 1;
                dc = 0;
            } else if (pc + 1 == e_col) {
                std::swap(dr, dc);
            }
        }
        pr += dr;
        pc += dc;
    }
};

int main(int argc, char** argv) {
    Solution sol;
    std::vector<std::vector<int>> mat = {{1,2,3,4},{5,6,7,8},{9,10,11,12},{13,14,15,16}};
    auto res = sol.rotateGrid(mat, 3);
    return 0;
}