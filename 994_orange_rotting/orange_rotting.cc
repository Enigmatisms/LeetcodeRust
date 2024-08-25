#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

/**
 * 很简单的 BFS 
 * 傻逼了，一开始用的 char，结果 top >> 4 有问题（变负数了）
 * 
 * runtime: 53.15%
 * memory:  21.25%
 */
class Solution {
public:
    #define INDEX_HASH(i, j) char(i << 4) | char(j)
    int orangesRotting(vector<vector<int>>& grid) {
        std::deque<std::pair<uint8_t, uint8_t>> fronts;
        int num_fresh = 0, rows = grid.size(), cols = grid[0].size();
        for (int i = 0; i < rows; i++) {
            const auto& vec = grid[i];
            for (int j = 0; j < cols; j++) {
                if (vec[j] == 1) num_fresh ++;
                else if (vec[j] == 2) fronts.emplace_back(INDEX_HASH(i, j), 0);
            }
        }
        if (num_fresh == 0) return 0;
        while (fronts.empty() == false) {
            auto [top, time] = fronts.front();
            fronts.pop_front();
            int i = top >> 4, j = top & 0x0f, &val = grid[i][j];
            if (time >= 1 && val == 2) continue;                        // 去重
            val        = 2;
            num_fresh -= (time >= 1);
            if (num_fresh == 0) return time;
            if (i > 0 && grid[i - 1][j] == 1)
                fronts.emplace_back(INDEX_HASH(i - 1, j), time + 1);
            if (i + 1 < rows && grid[i + 1][j] == 1)
                fronts.emplace_back(INDEX_HASH(i + 1, j), time + 1);
            if (j > 0 && grid[i][j - 1] == 1) 
                fronts.emplace_back(INDEX_HASH(i, j - 1), time + 1);
            if (j + 1 < cols && grid[i][j + 1] == 1) 
                fronts.emplace_back(INDEX_HASH(i, j + 1), time + 1);
        }
        return -1;
    }
};

int main(int argc, char** argv) {
    Solution sol;
    std::vector<std::vector<int>> oranges = 
     {{2,0,1,1,1,1,1,1,1,1},
      {1,0,1,0,0,0,0,0,0,1},
      {1,0,1,0,1,1,1,1,0,1},
      {1,0,1,0,1,0,0,1,0,1},
      {1,0,1,0,1,0,0,1,0,1},
      {1,0,1,0,1,1,0,1,0,1},
      {1,0,1,0,0,0,0,1,0,1},
      {1,0,1,1,1,1,1,1,0,1},
      {1,0,0,0,0,0,0,0,0,1},
      {1,1,1,1,1,1,1,1,1,1}};
     
    sol.orangesRotting(oranges);
    return 0;
}