#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <unordered_map>
#include <unordered_set>

using namespace std;

/**
 * 这道题很有意思，是经典的 状态转移 + DP
 * 其他题目估计也可以这么做，需要决策的时候，不同决策的结果用不同的块保存
 * runtime: 100.00%
 * memory:  42.24%
 */
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        std::vector<std::array<int, 3>> profits(prices.size(), {0, 0, 0});        // possess | just selled | not possess
        profits[0][0] = -prices.front();
        for (size_t i = 1; i < prices.size(); i++) {
            int cur_price = prices[i];
            auto& curr = profits[i], &last = profits[i - 1];
            curr[0] = std::max(last[0], last[2] - cur_price);
            curr[1] = last[0] + cur_price;
            curr[2] = std::max(last[1], last[2]);
        }
        return std::max(profits.back()[1], profits.back()[2]);
    }
};

int main(int argc, char** argv) {
    Solution sol;

    return 0;
}
