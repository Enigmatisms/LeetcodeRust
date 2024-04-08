#include <iostream>
#include <vector>
#include <numeric>
using namespace std;

/**
 * 这道题看起来并不那么 DP，但实际还是用DP解的。这道题与背包问题有关系吗？
 * 找不到可递推的子问题。并且注意，由于在过程中，我们会产生新的石头，所以问题子空间是会一直变的
 * 
 * 这个问题的等价问题也太难想了... 这个问题等价于 416
 * 可以证明（说实话，我都不知道他们是怎么想到的），如果把石头分成两堆（A,B）
 * 两堆互相粉碎，相当于 A * 1 - B * 1 (A 权重是 1, B 权重 是 -1)
 * 找到的两堆石头重量差的绝对值最小值，就是最后的石头重量
 * 也就是说，我们希望把石头划分为两份，两份之间的重量尽可能一致
 * 那么转化为什么问题呢？一个容量为 sum / 2 的背包，内部需要装尽可能重（价值等于重量）的石头
 * (1) 确定 DP 数组表示的意义
 * DP[k][i] 表示允许前 k 块石头，且背包大小为 i 时的最大重量
 * (2) 递推
 * DP[k][i]: 不装第 k 块，有 DP[k - 1][i]
 * 装第 k 块，有 DP[k - 1][i - weight[k]] + weight[k]
 * 所以，取两者之间的最大即可
 * (3) 初始化条件
 * 大于等于 weight[0] 时全为 weight[0]
 * (4) 空间复杂度优化
 * 显然可以，这里不赘述
 * 
 * 只能说，这道题可能难就难在等价问题不好想
 * 
 * runtime: 100.00%
 * memory:  82.40%
*/
class Solution {
public:
    int lastStoneWeightII(vector<int>& stones) {
        if (stones.size() <= 2) {
            stones.push_back(0);
            return std::abs(stones[0] - stones[1]);
        }

        int sum = std::accumulate(stones.begin(), stones.end(), 0), capacity = sum >> 1;        // capacity
        std::vector<int> dp(capacity + 1, 0);
        int first_weight = stones[0], num_stones = stones.size();
        for (int i = first_weight; i <= capacity; i++)
            dp[i] = first_weight;
        for (int k = 1; k < num_stones; k++) {
            int cur_weight = stones[k];
            for (int i = capacity; i >= cur_weight; i--) {
                dp[i] = std::max(dp[i], dp[i - cur_weight] + cur_weight);
            }
        }
        int neg_side = dp.back();           // 更小的那一半，石头总重量
        return sum - (neg_side << 1);       // (sum - neg) -> 更多那一半，减去 neg，为最后结果
    }
};

int main() {
  Solution sol;
  
  return 0; 
}