#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <unordered_set>

using namespace std;

/**
 * 重新尝试，DP 四部曲
 * 算是一个特殊的背包问题
 * (1) DP 数组的含义
 * DP[k][i] 代表，使用 word dict 前 k 个 word 时，对于字串 (长度为 i，也即下标最大为 i - 1)
 * 是否可以有至少一种 match 方式。注意 reduce 方式是 or
 * (2) 递推公式
 * DP[k][i] = DP[k - 1][i] or (DP[k - 1][i - str[k].length()] and str[i - str[k]:i] == str[k])
 * (3) 初始化
 * DP[0][0] = true
 * DP[0][1] = s[0...1] in wordDict ?
 * (4) 空间复杂度优化
 * 显然可以
 * 
 * 这道题的新做法基本一样。但结果快了一点，思路清晰多了
 * 
 * 这道题貌似并不是直接套完全背包的套路的，比如遍历方向就不一样，而且还可以 break
 * 
 * runtime: 83.51%
 * memory:  69.78%
 */
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int s_len = s.length(), num_word = wordDict.size();
        std::unordered_set<std::string> words(wordDict.begin(), wordDict.end());
        std::vector<bool> dp(s_len + 1, false);
        dp[0] = true;
        dp[1] = words.count(s.substr(0, 1)) > 0;
        for (int i = 2; i <= s_len; i++) {
            for (int j = i - 1; j >= 0; j--) {
                std::string suffix = s.substr(j, i - j);
                bool valid = dp[j] & (words.count(suffix) > 0);
                if (valid) {
                    dp[i] = valid;
                    break;
                }
            }
        }
        return dp.back();
    }
};

int main(int argc, char** argv) {
    Solution sol;

    return 0;
}