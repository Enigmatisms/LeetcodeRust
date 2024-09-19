#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/**
 * 深度优先搜索了...
 * runtime: 94.52%
 * memory:  21.82%
 */
const std::vector<std::pair<int, int>> DIRS = {
    {-1, 0}, {1, 0}, {0, -1}, {0, 1}
};
class Solution {
private:
    void dfs(vector<vector<char>>& grid, int i, int j, int rows, int cols) const {
        std::vector<std::pair<int, int>> jobs;
        jobs.reserve(8);
        jobs.emplace_back(i, j);
        grid[i][j] = '2';
        while (!jobs.empty()) {
            auto [row, col] = jobs.back();
            jobs.pop_back();
            for (auto [rd, cd]: DIRS) {
                int cur_r = row + rd, cur_c = col + cd;
                if (cur_r < 0 || cur_r >= rows || cur_c < 0 || cur_c >= cols) continue;
                char& val = grid[cur_r][cur_c];
                if (val != '1') continue;
                val = '2';
                jobs.emplace_back(cur_r, cur_c);
            }
        }
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        int rows = grid.size(), cols = grid[0].size();
        int num_grid = 0;
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (grid[i][j] == '1') {
                    num_grid ++;
                    dfs(grid, i, j, rows, cols);
                }
            }
        }
        return num_grid;
    }
};

int main(int argc, char** argv) {
    Solution sol;

    return 0;
}