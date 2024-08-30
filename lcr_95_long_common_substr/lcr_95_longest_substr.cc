#include <iostream>
#include <vector>
#include <array>
#include <algorithm>

using namespace std;

/**
 * 最长公共子序列，删掉中间的某些字母可以形成的最长序列
 * 看起来很难，不过一眼动态规划？
 * （1）表示：DP[i][j] 表示 text1[:i], text2[:j] 之间可以有的最长子序列
 * 
 * 二维的清楚表示：
 * （2）递推：DP[i][j] 需要求解时：二维情况下只考虑当前未知，i,j 向前推的三种情况全部已知
 * 如果 text1[i] == text2[j]，那么显然是 DP[i - 1][j - 1] + 1
 * 如果不等：则选更长的 max(DP[i - 1][j], DP[i][j - 1])
 *  (3) 初始化：i = 0 或者 j = 0 时，只要有一个为 0，就是 0（长度为 0不可能有子序列）
 * （4）压缩：可以，只需要保留上一列
 * 
 * 记住分析：假设 i, j 未知，[i - 1, j], [i, j - 1], [i - 1, j - 1] 都是已知的，去讨论
 * runtime: 89.36%
 * memory:  64.33%
 */
class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int len1 = text1.length(), len2 = text2.length();
        std::vector<int> dp(len2 + 1, 0);
        for (int i = 1; i <= len1; i++) {
            std::vector<int> new_dp(len2 + 1, 0);
            char c_i = text1[i - 1];
            for (int j = 1; j <= len2; j++) {
                char c_j = text2[j - 1];
                if (c_i == c_j) {
                    new_dp[j] = dp[j - 1] + 1;
                } else {
                    new_dp[j] = std::max(new_dp[j - 1], dp[j]);
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