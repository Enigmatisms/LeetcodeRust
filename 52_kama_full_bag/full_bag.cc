#include <iostream>
#include <vector>
#include <numeric>

/**
 * 完全背包问题，每一种物品可以选择无限次
 * (1) DP 数组的含义
 * DP[k][i] 表示 开放前 k 件物品能达到的最大价值
 * (2) 递推
 * 与 0-1 背包不同，我们可以重复选择
 * 重复选择这件事情，其实可以不用 DP[k][i - j * weight[k]], 遍历 j 这样实现
 * 虽然这是递推： DP[k][i] = max(DP[k - 1][i], DP[k][i - j * weight[k]] for j in range(1, ...?))
 * 但还记得 0-1 背包中，内层（背包容量）的遍历顺序吗？我们是从大到小进行遍历，就是为了避免选择重复元素
 * 
 * 那么此时我们可以从小到大遍历：小的先遍历将影响大的计算结果
 * (3) 初始化
 * DP[0][weight[k] ~ 2 * weight[k] - 1] = value[k]
 * DP[0][2 * weight[k] ~ 3 * weight[k] - 1] = 2 * value[k]
 * ... 等等
 * (4) 空间复杂度优化
 * 显然可以
 * runtime: 43ms
 * memory:  2176kb
 */
class Solution {
public:
    int maxValueBag(std::vector<int>& costs, std::vector<int>& weights, int m) const {
        int num_item = costs.size(), first_cost = costs[0], first_w = weights[0];
        if (num_item == 1) {
            return (m / first_w) * first_cost; 
        }
        std::vector<int> dp(m + 1, 0);
        for (int i = first_w; i <= m; i += first_w)
            dp[i] = first_cost;
        std::partial_sum(dp.begin(), dp.end(), dp.begin());
        for (int k = 1; k < num_item; k++) {
            first_w    = weights[k];
            first_cost = costs[k];
            for (int i = first_w; i <= m; i++)
                dp[i]  = std::max(dp[i], dp[i - first_w] + first_cost);
        }
        return dp.back();
    }
};

int main(int argc, char** argv) {
    Solution sol;
    int num_item = 0, m = 0;
    std::cin >> num_item >> m;
    std::vector<int> costs(num_item), weights(num_item);
    for (int i = 0; i < num_item; i++)
        std::cin >> weights[i] >> costs[i];
    
    std::cout << sol.maxValueBag(costs, weights, m) << std::endl;
    return 0;
}