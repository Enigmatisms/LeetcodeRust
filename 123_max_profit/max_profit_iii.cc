#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/**
 * 最多可以完成两笔交易... 所以决策过程可能涉及到对于交易次数的记录
 * 尝试一下，这道题是 hard，但毕竟是一系列题
 * 
 * (1) DP 数组的含义
 * 注意要限定时间：第 i 天结束时
 * DP[i][0] 此前未完成过交易，当前不持有时的最大值
 * DP[i][1] 此前未完成过交易，当前持有时的最大值
 * DP[i][2] 此前完成过一笔交易，当前不持有时的最大值
 * DP[i][3] 此前完成过一笔交易，当前持有时的最大值
 * 时间的限定：在 i - 1 天结束时及之前完成过交易。不包括今天
 * 
 * 感觉状态空间推得不是特别清楚，主要还是在：此前是否完成过交易
 * 如果包括今天，则 DP[i][0] 没有存在的意义，因为不管怎么样，我们都要求对应值不能发生交易
 * 所以不应该包含当前天
 * 
 * 则（2）递推
 * DP[i][0] = DP[i][0] <-- max --> DP[i - 1][1] + price[i]（由于是今天卖出的，所以仍然不算），但注意，后者已经在这一天结束时引入了一次交易
 * DP[i][1] = DP[i - 1][1] <-- max --> DP[i - 1][0] - price[i]，这倒是没什么问题
 * DP[i][2] 在第i天之前完成过一笔交易，则有可能是：
 * 从 DP[i - 1][0] 来，且继续不持有     
 * （i - 1 时刚卖出，但我怎么知道 DP[i - 1][0] 存的到底是完成交易的没有？如果没有完成交易还用这个岂不是算错？所以可能 DP 还需要存交易次数？）
 * 所以，i - 1 时具体是否完成过交易，目前从下标完全得不到信息，所以可能不能限制到 i - 1 天
 * 从 DP[i - 1][3] 来，且当前卖出
 * 从 DP[i - 1][2] 来，且继续不持有
 * ... 感觉链路不通
 * 
 * 如果限定在第 i 天结束之前，是否完成过交易，以及是否持有。那么 DP[i][0]: 此前没有完成任何交易，且当前不持有--貌似是不需要存在的。
 * 因为这个值始终会是 0，（但可能需要 clamp 所有结果到 0，不能做亏本买卖）
 * 
 * DP[i][1]: 此前没有完成过交易，第 i 天结束时持有：DP[i][1] = max(DP[i - 1][1], -price[i])     选择继续持有，还是在当前选择买入
 * DP[i][2]: 截止本日结束后完成过一次交易，且当前不持有。  
 *  DP[i][2] = max(DP[i  -1][2], DP[i - 1][1] + price[i], DP[i - 1][3] + price[i])
 * 此前没有完成交易，在本日完成了; 或者此前完成过，不持有且保持不持有状态; 或者此前完成过，且第二次买入，本次卖出
 * 注意，如果操作 2 或者操作 3 属于大的值，则只记录操作 1 的结果（我们只能记录只完成过一次交易的结果），result = max(操作2， 操作3)
 * DP[i][3] 截止本日结束后完成过一次交易，且当前持有。
 *  DP[i][3] = (1) 保持持有，DP[i][3] (2) 从不持有状态转为持有 DP[i][2] - price[i]，因为转持有不会完成交易，所以只能从 2 找  
 * 
 * 看出来了吗，上式中，只有 DP[i][2] 是可能产生结果的？这是正确的吗？不正确。交易一次也可以产生最大值（第二次一定亏本时），0 次也可以
 * (3) 初始化
 * DP[0][1] = -price[0]
 * DP[0][2] = 0
 * DP[0][3] = -price[0]
 * 
 * (4) 空间复杂度优化
 * 显然可以
 * 
 * 我成功了！也就是说，接下来，DP 很重要（Elden Ring 版中文）我的想法和答案基本上一致
 * 逐渐摸到 DP 的门道了
 * runtime: 74.06%
 * memory:  94.77%
 */
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int num_days = prices.size(), dp_1 = -prices[0], dp_2 = 0, dp_3 = dp_1, max_res = 0;
        for (int i = 1; i < num_days; i++) {
            // printf("Start of day %d (cur price = %d): [%d, %d, %d]\n", i, prices[i], dp_1, dp_2, dp_3);
            int new_dp_1 = std::max(dp_1, -prices[i]), new_dp_2 = dp_2;
            int sale_0 = dp_1 + prices[i], sale_1 = dp_3 + prices[i];
            if (sale_0 > dp_2) {                                                    // 只有 DP[i][1] 才会更新 DP[i][2]
                // 为什么？因为 DP[i][3] + prices[i] 是完成第 2 次交易的操作。我们不能用完成交易后的金额继续累上去算
                new_dp_2 = sale_0;
                max_res  = std::max(max_res, sale_0);
            }
            if (sale_1 > dp_2) {
                max_res = std::max(max_res, sale_1);
            }
            dp_3 = std::max(dp_3, dp_2 - (i == num_days - 1 ? 0 : prices[i]));      // 最后一天购入没有意义
            dp_2 = new_dp_2;
            dp_1 = new_dp_1;
            // printf("End of day %d (cur price = %d): [%d, %d, %d]\n", i, prices[i], dp_1, dp_2, dp_3);
        }
        return std::max(dp_3, max_res);     // dp_1 不用参与，dp_1 一定是负数
    }
};

int main(int argc, char** argv) {
    Solution sol;
    std::vector<int> prices = {3,3,5,0,0,3,1,4};
    std::cout << sol.maxProfit(prices) << std::endl;
    return 0;
}