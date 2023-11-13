#include <vector>
#include <iostream>

/**
 * 这道题做得出奇地差，对动态规划还是没有概念啊... 涉及到下标逻辑的时候就会很晕
 * runtime: 65.05%
 * memory:  18.15%
 * 此题需要重做
*/

class Solution {
public:
    int uniquePathsWithObstacles(const std::vector<std::vector<int>>& obstacleGrid) const {
        if (obstacleGrid.front().front() == 1) return 0;
        int n = static_cast<int>(obstacleGrid.size()), m = static_cast<int>(obstacleGrid.front().size());
        std::vector<std::vector<int>> storage(n, std::vector<int>(m, 0));
        storage.front().front() = 1;
        int all_steps = n + m - 1;
        for (int step = 1; step < all_steps; step ++) {
            int max_step = std::min(step + 1, m);
            bool blocked = true;
            for (int j = std::max(step - n + 1, 0); j < max_step; j++) {
                int i = step - j;
                // printf("step = %d, (%d, %d)\n", step, i, j);
                bool not_occupied = (obstacleGrid[i][j] == 0);
                if (i > 0 && j > 0) {
                    if (not_occupied) {
                        storage[i][j] = storage[i - 1][j] + storage[i][j - 1];
                        blocked = false;
                    }
                } else if (i == 0) {
                    if (not_occupied) {
                        storage[i][j] = storage[i][j - 1];
                        blocked = false;
                    }
                } else {
                    if (not_occupied) {
                        storage[i][j] = storage[i - 1][j];
                        blocked = false;
                    }
                }
            }
            if (blocked) {
                return 0;
            }
        }
        return storage.back().back();
    }
};

int main() {
    Solution sol;
    std::vector<std::vector<int>> obs{{0, 0, 0}, {0, 1, 0}, {0, 0, 1}, {0, 0, 0}};
    printf("Valid path num: %d\n", sol.uniquePathsWithObstacles(obs));
    return 0;
}