#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/**
 * 给人一种 DP 的纯真感
 * (1) DP 数组含义：DP[i] 表示以 i 结尾的最长连续子字符串的长度
 * (2) DP 递推：
 * - 如果 s[i] = s[i - 1] + 1，那么 DP[i] = DP[i - 1] + 1
 * - 反之如果不等于，则 DP[i] = 1
 * 此过程中不断记录最大值
 * (3) 初始条件，DP[0] = 1
 * (4) 是否可以压缩：可以
 * 
 * 这是中等题吗，我秒了啊
 * runtime: 84.96%
 * memory:  43.61%
 */
class Solution {
public:
    int longestContinuousSubstring(string s) {
        int last_len = 1, len = s.length(), max_len = 1;
        for (int i = 1; i < len; i++) {
            if (s[i] == s[i - 1] + 1) {
                last_len ++;
                max_len = std::max(max_len, last_len);
            } else {
                last_len = 1;
            }
        } 
        return max_len;
    }
};

int main(int argc, char** argv) {
    Solution sol;

    return 0;
}