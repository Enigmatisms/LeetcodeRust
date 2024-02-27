#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <unordered_map>
#include <unordered_set>

using namespace std;

/**
 * DP 好恶心，没有提示一下真的有些时候子问题都很难想
 * 记录一下回文串的性质:
 *  [i, j] (c) 可以取到，是闭区间 --> [i + 1, j - 1] (i + 1 < j) 也是回文串
 * 由于可以删去不想要的内容对应端点元素相等时，内部最长的回文串长度 + 2
 * 如果不相等，则说明当前端点不会构成回文串，最长回文串自然就是 [i + 1, j], [i, j - 1] 内最长的
 * 主要是这个循环的实现... 为什么要倒着来？不好好看转移方程就会想不出来，我们看看状态转移方程
 * 
 * long[i][j] = long[i + 1][j - 1] + 2,              if s[i] == s[j]
 * long[i][j] = max(long[i + 1][j], long[i][j + 1]), if s[i] != s[j]
 * 
 * 由于 i 总是要比自己大的值，所以可想而知，先算大的，后算小的。那么 j ?
 * - 当 j < i 时肯定是 0, 那么当 j 起始为 i 或者 i + 1 并且增的时候，边界的 j - 1 < i + 1 (比如 i = n - 2, j = n - 1) 就
 * 可以query到 0
 * - j == i 是算过的，就是 1, 所以 j 应该从 i + 1 开始。那么 j 是否应该递减？ j 递减没有意义： j <= i 要么是1要么是0
 * 这道题是否可以用O(n)的空间复杂度解决？ 感觉很难啊，这是斜着走的
 * runtime: 99.57%
 * memory:  84.80%
 */
class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int s_len = static_cast<int>(s.length());
        std::vector<std::vector<short>> longests(s_len, std::vector<short>(s_len, 0));
        for (int i = s_len - 1; i >= 0; i--) {
            longests[i][i] = 1;
            char ci = s[i];
            for (int j = i + 1; j < s_len; j++) {
                if (s[j] == ci) {
                    // for i = n-2, j = n-1, longests[n-1][n - 2] < 0;
                    longests[i][j] = longests[i + 1][j - 1] + 2;
                } else {
                    longests[i][j] = std::max(longests[i + 1][j], longests[i][j - 1]);
                }
            }
        }
        return longests.front().back();
    }
};

int main(int argc, char** argv) {
    Solution sol;

    return 0;
}