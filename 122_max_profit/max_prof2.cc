#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/**
 * 决策问题的 DP 数组一般都与决策本身有关
 * (1) DP 数组含义
 * DP[i][0] 表示第 i 天（结束时）不持有股票，可能是今天卖出的，也可能是之前卖出的但一直决定不持有
 *      此情况下获得的利润最大值
 * DP[i][1] 表示第 i 天结束持有股票，可能是这一天购入的，也可能是之前就持有的
 *      此情况下获得的利润最大值
 * (2) 递推公式：总感觉哪里不对 --- 我不知道买入股票时的价格 --- 没关系，此前会是负数，所以隐含在递推关系中了
 * DP[i][0] 可以是上一天就决定不持有，也可以是今天选择卖出（上一天有，今天卖出），上一天结束后不持有包括了上一天结束前卖出
 *      DP[i][0] = max(DP[i - 1][0], DP[i - 1][1] + price[i])
 * DP[i][1] 可以是上一天就持有，本日仍然不卖出，或是今天选择购入
 *      DP[i][1] = max(DP[i - 1][1], DP[i - 1][0] - price[i])
 * 递推关系非常清晰了
 * (3) 初始化
 * DP[0][0] = 0, DP[0][1] = -price[0]
 * (4) 空间复杂度优化
 * 当然可以，O(1)，每一个状态之和上一天结束时有关
 * 
 * 比第一个解清晰且简短很多！那肯定... 第一个解是暴力解
 * runtime: 100.00%
 * memory:  77.22%
 */
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int num_days = prices.size(), dp_0 = 0, dp_1 = -prices[0];
        for (int i = 1; i < num_days; i++) {
            int new_dp_0 = std::max(dp_0, dp_1 + prices[i]);
            dp_1 = std::max(dp_1, dp_0 - (i == num_days - 1 ? 0 : prices[i]));      // 最后一天买入也没有意义
            dp_0 = new_dp_0;
        }   
        return std::max(dp_0, dp_1);
    }
};

int main(int argc, char** argv) {
    Solution sol;

    return 0;
}