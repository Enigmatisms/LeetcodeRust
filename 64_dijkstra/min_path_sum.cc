#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <unordered_map>
#include <unordered_set>

using namespace std;

/**
 * Dijkstra 本身就是 DP
 * 以后记住，这样的题都可以axis-aligned 遍历，不要扩散式遍历
 * 这里你可以说是用了滚动数组。但我倾向于用绘图表示，绘图之后就会发现很简单
 * runtime: 97.24%
 * memory:  31.03%
 */
class Solution {
public:
    int minPathSum(const vector<vector<int>>& grid) const {
        int num_row = static_cast<int>(grid.size()), num_col = static_cast<int>(grid.front().size());
        std::vector<int> reservior = grid.back();
        for (int j = num_col - 2; j >= 0; j--)
            reservior[j] += reservior[j + 1];
        for (int i = num_row - 2; i >= 0; i--) {
            reservior[num_col - 1] += grid[i][num_col - 1];
            for (int j = num_col - 2; j >= 0; j--) {
                reservior[j] = grid[i][j] + std::min(reservior[j + 1], reservior[j]);
            }
        }
        return reservior[0];
    }
};

int main(int argc, char** argv) {
    Solution sol;

    return 0;
}