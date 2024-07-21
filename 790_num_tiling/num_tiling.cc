#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/**
 * 这道题实际上是2D的背包问题：
 * 有两个背包，6 种物体（横杠竖杠，tromino 有四个）
 * 选一个问题可能可以同时填充两个背包
 * 求恰好装满背包的种数
 * 直接这样建模都不一定能写出来，这里我们要考虑空余状态
 * 
 * 有四种，假设 DP[i] 为恰好到 i 列时各个状态的数量
 * 实际上只有这么几种状态
 * 
 * [1][0]         [1][0]         [1][1]          [1][1]
 * [1][0] (半满)  [1][1] （上差1）[1][0] （下差1)  [1][1] (全满)
 * 考虑横向的半满没什么意义，横向其实无法递推：竖向半满可以加 tromino，但横向没办法
 * 所以递推关系是能出来的（就是有点绕）
 * 其实我觉得这种递推关系不明显的题是最难做的
 * 
 * dp[i][0] = dp[i - 1][3]，这里是我做错了的地方：我一开始加了 dp[i - 1][0]，因为我觉得空 + 竖条也可以得到 dp[i]
 * 但这实际上会多算：如果认为是 i-1 全空（也即 i - 1列空的），增加 i 列时在 i - 1 列放一竖条
 * 实际上与dp[i - 1][3] 的一种情况（空加竖条至满）是重复了的
 * 
 * 注意本题是可以找规律的（递推公式）
 * 一开始想了，但是因为觉得去对称性很操蛋，所以没深究
 * runtime: 13.90%
 * memory:  5.12%
 */
constexpr long long mod = 1e9 + 7;
class Solution {
public:
    int numTilings(int n) {
        std::vector<std::vector<long long>> dp(n + 1, std::vector<long long>(4));
        dp[0][3] = 1;
        for (int i = 1; i <= n; i++) {
            dp[i][0] = dp[i - 1][3];
            dp[i][1] = (dp[i - 1][0] + dp[i - 1][2]) % mod;
            dp[i][2] = (dp[i - 1][0] + dp[i - 1][1]) % mod;
            dp[i][3] = (dp[i - 1][0] + dp[i - 1][1] + dp[i - 1][2] + dp[i - 1][3]) % mod;
        }
        return dp[n][3];
    }
};

int main(int argc, char** argv) {
    Solution sol;

    return 0;
}