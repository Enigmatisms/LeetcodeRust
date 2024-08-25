#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <unordered_map>
#include <unordered_set>

using namespace std;

/**
 * 动态规划与图解滚动数组真的解这些题跟tm切菜一样
 * runtime: 100.00%
 * memory:  37.19%
 */
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int num_rows = static_cast<int>(obstacleGrid.size()), num_cols = static_cast<int>(obstacleGrid.front().size());
        std::vector<int> reservior(num_cols, 0);
        for (int i = 0; i < num_cols; i++) {
            if (obstacleGrid.front()[i]) break;
            reservior[i] = 1;
        }
        for (int row = 1; row < num_rows; row++) {
            if (obstacleGrid[row][0]) reservior[0] = 0;
            for (int col = 1; col < num_cols; col++) {
                if (obstacleGrid[row][col]) {
                    reservior[col] = 0;
                    continue;
                }
                reservior[col] += reservior[col - 1];
            }
        }
        return reservior.back();
    }
};

int main(int argc, char** argv) {
    Solution sol;

    return 0;
}