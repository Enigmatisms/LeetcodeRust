#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/**
 * 背包问题，这里是双背包
 * 
 * (1) DP 的含义
 * DP[k][i][j] 表示，前 k 个物品，当 0 背包容量是 i，1 背包容量是 j 时最大的子集长度为 DP[k][i][j]
 * (2) 递推公式
 * 是否选择放入？如果不放入，等于 DP[k-1][i][j]
 * 放入则为: DP[k-1][i - num_zero[k]][j - num_one[k]] + 1
 * 两个取最大即可
 * (3) 初始化
 * DP[0][i][j]，在 i >= num_zero[0] && j >= num_one[0] 时都是 1
 * (4) 空间复杂度
 * 本题如果不优化，是 O(n * m * strs.size())
 * 优化以后是 O(n * m)
 * runtime: 86.24%
 * memory:  68.55%
 */
class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        int num_str = strs.size();
        std::vector<std::array<int, 2>> zero_one(num_str, {0, 0});      // 统计所有 zero one
        for (int i = 0; i < num_str; i++) {
            for (auto c: strs[i])
                ++zero_one[i][c - '0'];
        }
        std::vector<std::vector<int>> dp(m + 1, std::vector<int>(n + 1, 0));
        {
            auto [num_zero, num_one] = zero_one[0];
            for (int i = num_zero; i <= m; i++) {
                for (int j = num_one; j <= n; j++) {
                    dp[i][j] = 1;
                }
            }
        }
        for (int k = 1; k < num_str; k++) {
            auto [num_zero, num_one] = zero_one[k];
            for (int i = m; i >= num_zero; i--) {
                for (int j = n; j >= num_one; j--) {
                    dp[i][j] = std::max(dp[i][j], dp[i - num_zero][j - num_one] + 1);
                }
            }
        }
        return dp.back().back();
    }

    int findMaxForm_old(vector<string>& strs, int m, int n) {
        int num_str = strs.size();
        std::vector<std::vector<int>> dp(m + 1, std::vector<int>(n + 1, 0));        // 2D compression mapping
        std::vector<std::pair<int, int>> one_zeros;
        one_zeros.reserve(num_str);
        for (const auto& str: strs) {
            int s_len = str.length(), one_cnt = 0;
            for (char v: str) one_cnt += v == '1';
            one_zeros.emplace_back(s_len - one_cnt, one_cnt);
        }

        for (int i = 0; i <= m; i++) {
            for (int j = i == 0 ? 1 : 0; j <= n; j++) {
                for (auto [num_0, num_1]: one_zeros) {
                    if (i - num_0 < 0 || j - num_1 < 0) continue;
                    // not accurate
                    dp[i][j] = std::max(dp[i][j], dp[i - num_0][j - num_1] + 1);
                }
            }
        }
        return dp.back().back();
    }
};

int main(int argc, char** argv) {
    Solution sol;

    return 0;
}