#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

/**
 * DP 问题四部曲
 * (1) 确定 DP 数组及其下标含义
 * 首先，我们需要天数 i，另外，需要另行对决策进行记录
 * 所以，暂定 DP[k][i] 表示：在第 i 天，选择了商家 k (HASH) 获得的方案数
 * 注意，题目没有说“最”这个字眼，所以，reduce 方式应该是 sum 而不是 max
 * (2) 确定递推关系
 * DP[k][i] 可以将上一次所有不等于 k 的全部加起来，为本次的方案数
 * 故 DP[k][i] = max_{j != k}(DP[j][i - 1])
 * (3) 确定边界条件
 * DP[k][1] = 1 ---> 第一天，无论当前选什么，都是只有当前选择的这一种方案
 * (4) 空间复杂度优化
 * 显然，我们之和前一天的状态 [i-1] 有关，所以可以用 O(n) 复杂度解决
 * 但注意，i 应该是外层循环，所以应该用
 * DP[i][k] 来表示
 * 
 * 则本题思路比较清晰，可写
 */

constexpr long long MOD = 1e9+7;
int main(int argc, char** argv) {
    int num_day = 0;
    std::cin >> num_day;
    // 第一天的边界处理
    std::string choices;
    std::cin >> choices;
    std::unordered_map<char, long long> dp;
    for (char v: choices)
        dp[v] = 1;
    for (int i = 1; i < num_day; i++) {
        std::unordered_map<char, long long> new_dp;
        std::cin >> choices;
        for (char cur_vendor: choices) {
            long long num_choice = 0;
            for (auto [vendor, cnt]: dp) {
                if (cur_vendor == vendor) continue;
                num_choice = (num_choice + cnt) % MOD;
            }
            new_dp[cur_vendor] = num_choice;
        }
        dp = std::move(new_dp);
    }
    long long sum = 0;
    for (auto [_v, cnt]: dp)
        sum += cnt;
    std::cout << sum % MOD << std::endl;
    return 0;
}