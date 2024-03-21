#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/**
 * 本背包问题更为复杂: 限制是选过之后就不能再一次选择。
 * runtime: 
 * memory:  
 */
class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
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