#include <iostream>
#include <numeric>
#include <vector>
using namespace std;

/**
 * 这道题乍一看又很像分割数组为两个几乎相等的
 * 但实际上不是。题目所问的是，有多少不同的表达式可以使得结果等于目标值
 * 实际上在问什么呢？我们可以把一个目标数字T看成
 * T = A - B，A >= 0, B >= 0
 * 那么有：
 * A + B = sum (已知)
 * A - B = T
 * 则 可以解出: A = (sum + T) / 2, B = (sum - T) / 2
 * 那么实际上是个什么问题？
 * 假设有一个容量大小为 B 的背包，请问，有多少种方式可以“恰好”将其装满，此乃DP也
 * (1) DP数组的含义
 * DP[k][i] 表示，前 k 个物体，恰好装满容量为 i 的背包的方法数为 DP[k][i]
 * (2) 递推公式
 * DP[k][i] = (不装第k个) DP[k-1][i] + (装第k个时，如果 i - weight[k] 已经有对应几种装入方式了，则累加之)DP[k - 1][i - weight[k]]
 * (3) 初始化
 * DP[0][weight[0]] = 1，其余时候都为 0
 * 注意！！！ DP[0][0] 至少为 1。DP[any][0] 考虑的是恰好 只剩下当前物体这么大的容量的情况
 * 这个边界处理，怎么说呢... 是否有一开始就可以想到的？
 * 那么这样吧，以后这种题，首先上来总是先注意 DP[0][0] 具体应该是多少，不要想当然
 * (4) 空间复杂度优化：可以
 * (5) 特殊情况
 *  0 比较特殊。如果 0 作为初始化，那么 DP[0][0] = 2 (因为可正可负，两种情况)
 * 
 * runtime: 100.00%
 * memory:  63.73%
*/

class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int num_num = nums.size();
        if (num_num == 1) return (nums[0] == target) + (-nums[0] == target);
        int sum = std::accumulate(nums.begin(), nums.end(), 0), abs_target = std::abs(target);
        if (sum < abs_target || ((sum - target) & 1)) return 0;
        int capacity = (sum - target) >> 1, first_num = nums[0];
        std::vector<int> dp(capacity + 1, 0);
        dp[0] = 1;
        if (first_num <= capacity)
            ++ dp[first_num];
        for (int k = 1; k < num_num; k++) {
            int cur_num = nums[k];
            for (int i = capacity; i >= cur_num; i--) {
                dp[i] += dp[i - cur_num];
            }
        }
        return dp.back();
    }
};

int main() {
  Solution sol;
  
  return 0; 
}