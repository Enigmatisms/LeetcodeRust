#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/**
 * 法环味中文：
 * 有 DP 的感觉... 果然是 DP
 * 接下来，DP 将会很好用
 * 前有 DP，所以前有码
 * DP 四部曲
 * (1) 确定 DP 数组含义
 * DP[i] 表示跳到第 i 格花费的最大步数
 * (2) 确定递推关系
 * DP[i] = max(1 + DP[i - k] if |nums[k] - nums[i]| <= target)
 * (3) 确定初始化
 * DP[0] = 0
 * (4) 判定是否可以进行空间或者时间优化
 * 由于我们需要对之前所有的值进行reduce，个人觉得时间复杂度是 O(n^2) 估计优化不了
 * 空间复杂度 O(n) 估计也很难优化
 * 
 * 很简单嘛
 * runtime: 96.35%
 * memory:  85.42%
 */
class Solution {
public:
    int maximumJumps(vector<int>& nums, int target) const {
        int num_size = nums.size();
        std::vector<int> dp(num_size, 0);
        for (int i = 1; i < num_size; i++) {
            int max_v = -1, num_i = nums[i];
            for (int j = 0; j < i; j++) {
                int diff = num_i - nums[j];
                if (diff > target || diff < -target || dp[j] < 0) continue;
                max_v = std::max(max_v, dp[j] + 1);
            }
            dp[i] = max_v;
        }
        return dp.back();
    }
};

int main(int argc, char** argv) {
    Solution sol;

    return 0;
}