#include <iostream>
#include <vector>

using namespace std;

/**
 * 来自 https://kamacoder.com/problempage.php?pid=1046
 * 0-1 背包问题。我们同样也尝试自己建模
 * 行李空间 N，一共 M 类研究材料
 * M 类研究材料会有一个对应的 value 列表表示每一个材料的价值。求最大价值
 * (1) 确定 DP[i] 的含义
 * DP[i]：背包空间为 i 时，可携带的最大价值
 * (2) 确定递推公式
 * 每遇到一件物品，我们需要做出决策：是否将其放入？如果放入（能放入的话）
 * - 则当前的价值会是 DP[i - weight[k]] + value[k]
 * 如果不放入，则 DP[i] 一定会是 [0， i - 1] 中最大那一个（前面都能装下对应的 value，容量大了更能装下）
 * 注意，这里多了一个 k，我们会发现，k 和 i 是独立的（和那些一维的题目明显不同，比如当前是 i
 * 我们最多只需要算到 i - 1 之类的，k 的取值 和 i没有关系） ---> 这提示我们需要走 2D 的 DP 数组
 * 尝试这样决策：DP[i][k] 表示，容量为 i，种类最多到k类时（也即当前新加入了第k种物品）的最大 cost
 * 
 * 所以这下可以状态转移了
 * DP[i][k] 要么等于 DP[i][k - 1] (表示我根本不放 第k件)，要么就是放第k件
 * DP[i][k] = std::max(DP[i][k - 1], DP[i - weight[k]][k] + value[k])
 * 
 * 注意，k 应该是外层循环（一件一件物品判定的），所以应该反一下
 * 
 * DP[k][i] = std::max(DP[k - 1][i], DP[k][i - weight[k]] + value[k])
 * (3) 边界条件
 * 放入第一件物品时，显然应该是：DP[0][i < weight[0]] = 0, DP[0][i >= weight[0]] = value[0]
 * (4) 空间复杂度优化
 * 显然是可以优化的，我们只会考虑到与开放前 k-1 件物品，所以实际只需要一个多余的数组
 * runtime: 
 * memory:  
 */
class Solution {
public:
    int max_value_bag(int n, int m, const std::vector<int>& values, const std::vector<int>& weights) const {
        std::vector<int> dp(n + 1, 0);
        int cur_w = weights[0], cur_v = values[0];
        // 初始化
        for (int i = cur_w; i <= n; i++)
            dp[i] = cur_v;
        for (int k = 1; k < m; k++) {
            cur_w = weights[k];
            cur_v = values[k];

            // 注意，这里有一个这样的情况，如果我们是递增遍历，就必须要用两个 dp 数组
            // 因为我们不希望后续的计算会被前面的计算影响。所以要么：我们递减遍历。要么，用两个数组
            // for (int i = cur_w; i <= n; i++) {      // i 为允许的背包大小（不断测试背包越来越大）
            // 这里我们递减遍历
            for (int i = n; i >= cur_w; i--)           // 到 cur_w 就行，小于 cur_w 是没办法把当前物品放进来的，所以不影响
                dp[i] = std::max(dp[i], dp[i - cur_w] + cur_v);
        }
        return dp.back();       // DP[k][i]
    }
};

int main(int argc, char** argv) {
    Solution sol;
    int n = 0, m = 0;
    std::cin >> m >> n;
    std::vector<int> weights(m), values(m);
    for (int i = 0; i < m; i++)
        std::cin >> weights[i];
    for (int i = 0; i < m; i++)
        std::cin >> values[i];
    std::cout << sol.max_value_bag(n, m, values, weights) << std::endl;
    return 0;
}