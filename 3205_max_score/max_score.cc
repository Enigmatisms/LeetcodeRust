#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

/**
 * 给定一个数组 nums，你必须从索引 0 开始跳跃，直到到达数组的最后一个元素，使得获取 最大 分数。
 * 每一次 跳跃 中，你可以从下标 i 跳到一个 j > i 的下标，并且可以得到 (j - i) * nums[j] 的分数。
 * 
 * 2 <= nums.length <= 103
 * 1 <= nums[i] <= 105
 * 
 * 这是个 DP 问题
 * 1. DP 数组的含义
 * DP[i] 表示跳跃到下标为 i 处的最大分数
 * 
 * 2. DP 的递推关系
 * 需要回溯去搜索，从 i - 1 开始乘以对应的值
 * 
 * 3. 初始化
 * DP[0] 显然是 0
 * 
 * 4. 能否压缩：目前看不能
 * 
 * 也是3min内一遍AC，完全没有难度
 * runtime: 62.50%
 * memory:  40.63%
 */
class Solution {
public:
    int maxScore(vector<int>& nums) {
        int num_len = nums.size();
        std::vector<int> dp(num_len, 0);
        for (int i = 1; i < num_len; i++) {
            int i_score = nums[i], max_score = i * i_score;
            for (int j = 0; j < i; j++) {
                max_score = std::max((i - j) * i_score + dp[j], max_score);
            }
            dp[i] = max_score;
        }
        return dp.back();
    }
};

int main(int argc, char** argv) {
    Solution sol;

    return 0;
}