#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <unordered_map>
#include <unordered_set>

using namespace std;

/**
 * 这里涉及到决策，并且注意，决策相关的变量是首尾相连的
 * 
 * (1) DP 数组的含义 dp[k][0/1]: 只偷前 k 间房屋：
 *  dp[k][0] 不偷第 k 间房屋的最大盗窃金额
 *  dp[k][1] 偷第 k 间房屋的最大盗窃金额
 * (2) 递推公式
 * 涉及到决策。对于第 k 间房屋，如果我们不盗窃，那么显然是:
 * dp[k][0] = max(dp[k-1][0], dp[k - 1][1])，也即在上一种情况中选最大（可以选择盗窃或者不盗窃第 k - 1 间房子）
 * dp[k][1] = dp[k - 1][0] + gold[k], k - 1 必须不被盗窃才能盗窃 k
 * 
 * 注意一个边界: k 为 “最后一间”房子时，第一间房子必须不盗窃
 * 而随着递推的进行，第一间房子是否盗窃的信息可能已经没了，也即 k - 1 间房并不知道当前的最优是否涉及到第一间房被盗窃
 * 所以，dp[k][0] 可能需要兼顾记录一下第一间房间的盗窃信息。也即状态多了一些：
 * dp[k][0] 第一间房没有被盗窃，且不盗窃第 k 间
 * dp[k][1] 第一间房没有被盗窃，且盗窃第 k 间
 * dp[k][2] 第一间房被盗窃，且不盗窃第 k 间
 * dp[k][3] 第一间房被盗窃，且盗窃第 k 间
 * 
 * cost 更新规则为:
 * dp[k][0] = max(dp[k-1][0], dp[k-1][1])       // 第 k 间没有被盗，那么顺着查 k - 1，选择盗或者不盗都可以
 * dp[k][1] = dp[k - 1][0] + gold[k]            // 只有上一间房没被盗窃，且第一间也没有，才能盗窃
 * dp[k][2] = max(dp[k-1][2], dp[k-1][3])       // 第 k 间没有被盗，那么顺着查 k - 1，选择盗或者不盗都可以
 * dp[k][3] = dp[k - 1][2] + gold[k]            // 注意，此规则可以用于最后一个房间。只不过最后一个房间我们最后max时只取 0, 1, 2 情况，3不可能发生所以不取
 * 
 * (3) 初始化
 * dp[0][0] 显然是 0
 * dp[0][1] ... 1 没被盗，但我们又要盗 1，很矛盾，所以 0
 * dp[0][2] ... 1 被盗，但我们又不要盗 1，很矛盾，所以 0
 * dp[0][3] ... 1 被盗，且我们要盗 1，所以 gold [0]
 * 
 * (4) 空间复杂度优化
 * 显然可以，可以优化到 O(1)，因为只与上一个状态有关
 * 
 * 非常好题目，使我的头晃动
 * 
 * runtime: 100.00%
 * memory:  71.22%
 */
class Solution {
public:
    int rob(vector<int>& nums) {
        int num_houses = nums.size();
        if (num_houses == 1) return nums[0];
        int dp_0 = 0, dp_1 = 0, dp_2 = 0, dp_3 = nums[0];
        for (int k = 1; k < num_houses; k++) {
            int cur_gold = nums[k],
                new_dp_0 = std::max(dp_0, dp_1),
                new_dp_1 = cur_gold + dp_0,
                new_dp_2 = std::max(dp_2, dp_3),
                new_dp_3 = cur_gold + dp_2;
        }
        return std::max(std::max(dp_0, dp_1), dp_2);
    }
};

int main(int argc, char** argv) {
    Solution sol;

    return 0;
}