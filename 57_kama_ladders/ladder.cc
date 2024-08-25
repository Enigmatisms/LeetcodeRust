#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <unordered_map>
#include <unordered_set>

using namespace std;

/**
 * 显然也是背包问题，不过需要考虑恰好装满
 * 以及，这是一个排列问题，排列问题需要多次遍历可能选择，所以内循环应该是遍历选择（物品）
 * (1) DP 数组以及含义
 * DP[i][k] 表示有前 k 种步长选择时，爬到 i 处时有的方案数。注意 reduce 方法是 sum
 * (2) 递推公式
 * DP[i][k] 等于 sum(DP[i][0...k-1]) 注意，k-1 要被 clamp 到 i（不能超过）
 * 所以一直是 prefix sum 的状态？
 * prefix sum 是可以优化的
 * runtime:
 * memory:
 */
class Solution {
public:
    int ladder(int stairs, int max_allowed) const {
        if (max_allowed == 1) return 1;
        std::vector<int> dp(stairs + 1, 0);
        dp[0] = 1;
        dp[1] = 1;
        for (int i = 2; i <= stairs; i++) {
            for (int step = 1; step <= std::min(max_allowed, i); step ++) {
                dp[i] += dp[i - step];
            }
        }
        return dp.back();
    }
};

int main(int argc, char** argv) {
    Solution sol;
    int stairs = 0, max_allowed = 1;
    std::cin >> stairs >> max_allowed;
    std::cout << sol.ladder(stairs, max_allowed) << std::endl;
    return 0;
}