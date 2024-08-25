#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/**
 * 这道题非常巧妙：附件是用来扩充主件的
 * 比如主件是A，附件是 B，C，那么就会有
 * A, A + B, A + C, A + B + C 四种可购买的情况，但是这四种是互斥的（选了一种就不能选其他的）
 * 所以，每次选择主件时，都是在至多这四种情况中选择一种
 * 
 * (1) DP数组的含义
 * DP[i][k] 表示开放前 k 件主件时，如果背包容量为 i，最大的满意度
 * (2) 递推关系
 * 注意，由于不能重复选择，所以是从大到小遍历 k 的
 * DP[i][k] = max(
 *      DP[i][k - 1],                                   --> 不买
 *      DP[i - v[k1]][k - 1] + w[k1] * v[k1],           --> 只买主件（k1）
 *      DP[i - v[k2]][k - 1] + sum(...)                 --> 买主件与附件1
 *      DP[i - v[k3]][k - 1] + sum(...)                 --> 买主件与附件2
 *      DP[i - v[k4]][k - 1] + sum(...)                 --> 买主件与附件1 + 2
 * )
 * 并非所有情况都可能出现，但完整的递推公式就是这样，我们只遍历主件
 * (3) 初始化
 * DP[i][0] --> 有至多四个位置需要填空（k1, k2, k3, k4）
 * (4) 空间优化
 * k 这个维度可以优化，所以空间复杂度是 O(n)
 * 我觉得没什么问题
 * runtime: 
 * memory:  
 */
class Solution {
public:
    int max_satisfaction(
        const std::vector<std::vector<int>>& prices, 
        const std::vector<std::vector<int>>& satis, 
        int M
    ) const {
        std::vector<int> dp(M + 1, 0);
        int num = prices.size();        // 主件数量
        for (int k = 1; k < num; k++) {
            const auto& prices_k = prices[k];
            const auto& satis_k  = satis[k];
            int price = prices_k[0];
            for (int i = M; i >= price; i--) {
                int max_val = dp[i];
                for (size_t j = 0; j < prices_k.size(); j++) {
                    if (prices_k[j] > i) break;
                    max_val = std::max(max_val, dp[i - prices_k[j]] + satis_k[j]);
                }
                dp[i] = max_val;
            }
        }
        return dp.back();
    }
};

int main(int argc, char** argv) {
    Solution sol;
    int M, num_obj;
    std::cin >> M >> num_obj;
    std::vector<std::vector<int>> prices;
    std::vector<std::vector<int>> satis;
    for (int i = 0; i < num_obj; i++) {
        int price, import, is_adj, w_sat;
        std::cin >> price >> import >> is_adj;
        w_sat = price * import;
        if (is_adj) {       // 是附件
            prices.back().push_back(price + prices.back()[0]);
            satis.back().push_back(w_sat + satis.back()[0]);
        } else {            // 不是附件
            if (prices.empty() == false && prices.back().size() > 2) {
                prices.back().push_back(prices.back()[1] + prices.back()[2] - prices.back()[0]);        // (A + B) + (A + C) - A = A + B + C
                satis.back().push_back(satis.back()[1] + satis.back()[2] - satis.back()[0]);
            }
            prices.push_back({price});
            satis.push_back({w_sat});
        }
    }
    std::cout << sol.max_satisfaction(prices, satis, M) << std::endl;
    return 0;
}