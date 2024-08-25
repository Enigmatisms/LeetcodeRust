#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/**
 * (1) DP 数组以及下标含义
 * DP[i] 表示到达第 i 个台阶时花费的【最小】cost（注意，题目隐含了 reduce 方法）
 * (2) 递推公式
 * 只要我们支付了 cost[i]，就可以向上爬 1 或者 2 级
 * 也就是说，DP[i] 实际上要不等于 DP[i - 1] + cost[i - 1] (从i - 1到i)
 *                      要不等于 DP[i - 2] + cost[i - 2] (从i - 1到i)
 * (3) 初始化条件 DP[0] = 0, DP[1] = 0 (因为我可以选择从1开始爬)
 * (4) 空间优化：可以，也是只要存两个状态
 * 
 * DP 比我之前的解答慢，但是思路很简单啊，秒杀
 * runtime: 22.24%
 * memory:  69.31%
 */
class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int num_stairs = cost.size();
        int prev_2 = 0, prev_1 = 0, cur = 0;
        for (int i = 2; i <= num_stairs; i++) {
            cur = std::min(prev_2 + cost[i - 2], prev_1 + cost[i - 1]);
            prev_2 = prev_1;
            prev_1 = cur;
        }
        return cur;
    }
};

int main(int argc, char** argv) {
    Solution sol;

    return 0;
}