#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/**
 * 这道题不用考虑 y，只需要考虑 x
 * 问题转化为：将 n 个 x 轴上的点分成若干个跨度不超过 w 的份
 * 所以说就是排序 + 贪心，这个思路怎么说呢
 * 很好想，但是想出来不确定是否对，这让我很苦恼
 * 
 * 就是我一直在想，这道题如何判断是否能贪心？如果贪心引入局部最优会怎么样？
 * 反正贪心就是一遍过
 * runtime: 78.21%
 * memory:  37.77%
 */
class Solution {
public:
    int minRectanglesToCoverPoints(vector<vector<int>>& points, int w) {
        std::vector<int> x_axis(points.size());
        for (size_t i = 0; i < points.size(); i++) x_axis[i] = points[i].front();
        std::sort(x_axis.begin(), x_axis.end());
        auto it = x_axis.begin();
        int num_rect = 0;
        while (it != x_axis.end()) {
            it = std::upper_bound(it, x_axis.end(), (*it) + w);
            ++ num_rect;
        }
        return num_rect;
    }
};
int main(int argc, char** argv) {
    Solution sol;

    return 0;
}