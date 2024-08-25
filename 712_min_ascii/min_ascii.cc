#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <unordered_map>
#include <unordered_set>

using namespace std;

/**
 * 这道题还算想出来了，毕竟与 72 很像，先做了 72 再做这个就没啥思路上的问题
 * 还是判定从 s[i] 转 t[j] -> 相等则等于之前的 i - 1, j - 1 值，不想等就要判断删哪个
 * runtime: 99.23%
 * memory:  34.82%
 */
class Solution {
public:
    int minimumDeleteSum(string s1, string s2) {
        int src_l = static_cast<int>(s1.length()), dst_l = static_cast<int>(s2.length());
        std::vector<int> dp(dst_l + 1, 0);
        for (int i = 1; i <= dst_l; i++)
            dp[i] = dp[i - 1] + static_cast<int>(s2[i - 1]);
        for (int i = 1; i <= src_l; i++) {
            std::vector<int> new_dp(dst_l + 1, 0);
            char wi = s1[i - 1];
            new_dp.front() = dp.front() + static_cast<int>(wi);
            for (int j = 1; j <= dst_l; j++) {
                if (wi == s2[j - 1])
                    new_dp[j] = dp[j - 1];
                else {
                    new_dp[j] = std::min(new_dp[j - 1] + static_cast<int>(s2[j - 1]), dp[j] + static_cast<int>(wi));
                }
            }
            dp = std::move(new_dp);
        }
        return dp.back();
    }
};

int main(int argc, char** argv) {
    Solution sol;

    return 0;
}