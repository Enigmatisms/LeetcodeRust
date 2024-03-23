#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/**
 * 一眼背包秒杀
 * runtime: 54.76%
 * memory:  70.39%
 */
constexpr int I32MAX = 1e4 + 1;
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        std::vector<int> dp(amount + 1, 0);
        for (int i = 1; i <= amount; i++) {
            int min_num = I32MAX;
            for (int coin: coins) {
                if (i - coin < 0) continue;
                min_num = std::min(dp[i - coin] + 1, min_num);
            }
            dp[i] = min_num;
        }
        return dp.back() == I32MAX ? -1 : dp.back();
    }
};

int main(int argc, char** argv) {
    Solution sol;

    return 0;
}