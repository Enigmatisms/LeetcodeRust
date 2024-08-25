#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;

/**
 * DP四部曲，这道题并没有明显的 DP 样子。主要问题在于不知道如何设置子问题，以及确定 DP 数组的含义
 * 实际上，这是个背包问题：求数组总和。如果数组总和是奇数，直接返回false，否则
 * 背包容量是 sum / 2，求有没有一种方案，恰好可以装满背包（恰好装满问题）
 * (1) DP 含义
 * 我们尝试考虑 DP[k][i] (二维数组)，k 表示选择第 k 个物品时，i 表示背包容量为 i 时
 * DP[k][i] 是 0, 1 的 bool 数组：前 k 个物品是否可以把容量为 i 的背包装满？可以：1，不可以 0
 * (2) 怎么去递归
 * 当前是否放置第k个物体：
 * 1. 放置第k个，则前 k - 1 需要能恰好装满。故：DP[k][i] = DP[k - 1][i - weight[k]]
 * 2. 不放置第k个，则 k - 1 也需要恰好能装满: DP[k][i] = DP[k - 1][i]
 * 所以应该是：DP[k][i] = DP[k - 1][i - weight[k]] | DP[k][i] = DP[k - 1][i] （或的关系，只要有一种情况可以，那么就可以）
 * (3) 初始化
 * 第一个数字只在对应位置设 true，其他地方都是 false
 * (4) 是否可以优化空间复杂度？
 * 显然可以
 * 
 * 这题，有很多没考虑到的地方：
 * (1) 如果出现某个数字大于一半，显然需要直接退出：因为不可能成功
 * (2) 遍历顺序问题，本题竟然没考虑，之前0-1背包还考虑了
 * 为了防止重复取用，就需要倒着走
 * runtime: 33.46%
 * memory:  91.60%
 */
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        if (nums.size() == 1) return false;
        int sum = std::accumulate(nums.begin(), nums.end(), 0);
        if (sum & 1) return false;
        sum >>= 1;              // 目标数字、
        int num_digits = nums.size();
        std::vector<bool> dp(sum + 1, false);
        if (nums[0] > sum) return false;
        dp[nums[0]] = true;
        for (int k = 1; k < num_digits; k++) {
            int num = nums[k];
            if (num > sum) return false;
            for (int i = sum; i >= num; i--) {
                dp[i] = dp[i] | dp[i - num];
            }
            if (dp.back()) return true;
        }
        return false;
    }
};

int main(int argc, char** argv) {
    Solution sol;
    std::vector<int> nums = {2, 2, 3, 5};
    sol.canPartition(nums);
    return 0;
}