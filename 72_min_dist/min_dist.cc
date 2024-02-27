#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <unordered_map>
#include <unordered_set>

using namespace std;

/**
 * 首先需要知道： [i, j] 从 src[i] 变到 dst[j] 所需要花的最小cost
 * 那么 DP[i, j] 与计算过的值有什么关系？
 * 如果 src[i] == dst[j] 说明这一步就不需要进行操作，则 DP[i, j] == DP[i - 1, j - 1]
 * 如果不相同？说明要进行一次操作：三种情况 src 插入、替换与删除
 * 这三种操作是有明确的位置的，DP[i - 1, j - 1] + 1 说明，我们从 src[... i-1] <-> dst[..., j - 1]
 * 只需要替换 src[i] 与 dst[j] 相同
 * DP[i - 1, j] + 1 说明 src[i - 1] 与 dst[j] 一致，那么我们应该删掉 src[i]
 * DP[i, j - 1] + 1 说明 src[i] 与 dst[j - 1] 一致，那么我们应该删掉 dst[j], 等价于 src[i + 1]插入 dst[j]
 * 选三种情况的最小情况
 * 注意边界：DP[0][0] = ? 不一定是 0 或者 1, 由于我们要用到小一个index 的，索性让整个DP变大一圈（外边界不变）
 * 表示从空字符串变为对方k index 所需要的cost
 * runtime: 100.00%
 * memory:  35.31%
 */
class Solution {
public:
    int minDistance(string word1, string word2) {
        int src_l = static_cast<int>(word1.length()), dst_l = static_cast<int>(word2.length());
        std::vector<short> dp(dst_l + 1, 0);
        std::iota(dp.begin(), dp.end(), 0);
        for (int i = 1; i <= src_l; i++) {
            std::vector<short> new_dp(dst_l + 1, 0);
            new_dp.front() = i;
            char wi = word1[i - 1];
            for (int j = 1; j <= dst_l; j++) {
                if (wi == word2[j - 1])
                    new_dp[j] = dp[j - 1];
                else {
                    // new_dp[j - 1] -> dp[i][j - 1], dp[j - 1] -> dp[i-1][j-1], dp[j] -> dp[i - 1][j]
                    // (1) delete in word2 (2) substitude in word1 and word2 (3) delete in word[1] 
                    new_dp[j] = std::min(
                        std::min(new_dp[j - 1], dp[j - 1]), std::min(dp[j - 1], dp[j])
                    ) + 1;
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