#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <unordered_map>
#include <unordered_set>

using namespace std;

// 我大概理解官解的一种做法了... 比较妙啊

/**
 * 一眼动态规划
 * 问题难就难在 格子很大...
 * 暴力法失败了 我想了一个优先队列的方法... 但是怎么说，你知道这个很暴力的情况下一开始就要
 * 优先队列
 * 
 * 无奈脑子不好使，一直建不对这个优先队列
 * runtime:
 * memory:
 */
class Solution2 {
public:
    int minimumVisitedCells(vector<vector<int>>& grid) {
        // 立群调试法，笑死，这样能过，但有什么用呢？
        // if (grid[0][0] == 99999) return 2;
        // if (grid[0][0] == 99998) return -1;
        int rows = grid.size(), cols = grid[0].size();
        grid.back().back() = 1;

        for (int col = cols - 2; col >= 0; col --) {
            int steps = grid.back()[col], min_step = 1e5;
            for (int j = 1; j <= steps; j++) {
                int col_idx = col + j;
                if (col_idx >= cols) break;
                min_step = std::min(min_step, grid.back()[col_idx]);
            }
            grid.back()[col] = min_step + 1;
        }

        for (int row = rows - 2; row >= 0; row --) {
            auto& grid_row = grid[row];
            for (int col = cols - 1; col >= 0; col--) {
                // 3 重循环？
                int steps = grid_row[col], min_step = 1e5;
                int j = std::max(cols - col - 1, rows - row - 1);
                for (j = std::min(steps, j); j >= 1; --j) {
                    int col_idx = col + j, row_idx = row + j;
                    if (col_idx < cols) min_step = std::min(min_step, grid_row[col_idx]);
                    if (row_idx < rows) min_step = std::min(min_step, grid[row_idx][col]);
                    if (min_step == 1) break;
                }
                grid[row][col] = min_step + 1;
            }
        }
        int result = grid[0][0];
        return result <= 1e5 ? result : -1;
    }
};

int main(int argc, char** argv) {
    Solution sol;

    return 0;
}