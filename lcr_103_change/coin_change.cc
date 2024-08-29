#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/**
 * 典型的背包问题
 * 无限硬币，可以恰好装满背包时所花的最少个数
 * 
 * 1. 表示
 * DP[i] 表示有 i 元需要组成时，所花的最少个数
 * 2. 递推公式
 * DP[i] = std::min(DP[i - 5] + 1, DP[i - 2] + 1, DP[i - 1] + 1)
 * 三种情况选一种
 * 3. 初始化
 * 
 * 注意什么叫恰好满足。不要上去就似乎递推，如果 i - 5，i - 2 之类的值是 unreachable 的，那就跳过
 * runtime: 73.84%
 * memory:  37.80%
 */
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        // 单个 coin
        if (coins.size() == 1) {
            return amount % coins[0] ? -1 : amount / coins[0];
        }
        std::vector<int> dp(amount + 1, -1);
        dp[0] = 0;
        // 初始化
        int min_c = 1e4;
        for (int coin: coins) {
            if (coin < amount) {
                dp[coin] = 1;
            } else if (coin == amount) {
                return 1;
            }
            min_c = std::min(min_c, coin);
            // 大于 amount 的coins都是没用的
        }
        for (int i = min_c + 1; i <= amount; i++) {
            int min_v = 1e5;
            for (int coin: coins) {
                if (coin > i) continue;
                if (dp[i - coin] == -1) continue;       // 不可行的组合
                min_v = std::min(dp[i - coin] + 1, min_v);
            }
            if (min_v < 1e5)
                dp[i] = min_v;
        }
        return dp.back();
    }
};

int main(int argc, char** argv) {
    Solution sol;

    return 0;
}