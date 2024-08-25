#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/**
 * 重做此题，上一次做差不多是6个月前
 * 
 * （1）DP的含义
 * DP[i][0] 代表不偷 i 家的当前最大收益
 * DP[i][1] 代表偷 i 家
 * （2）递推公式
 * DP[i][0] = std::max(DP[i - 1][0], DP[i - 1][1])      // 现在不偷，则两种可能
 * DP[i][1] = DP[i - 1][0] + arr[i]                     // 现在偷，则上一家一定没偷
 * （3）初始状态
 * DP[i][0] = 0
 * DP[i][1] = arr[i]
 *  (4) 压缩
 * 可以，只需要两个状态
 * runtime: 32.65%
 * memory:  75.91%
 * 
 * 这tm比上一个版本简洁多了，但是... 竟然慢 + 内存大了？扯淡吧
 */
class Solution {
public:
    int rob(const vector<int>& nums) const noexcept {
        int rob_0 = 0, rob_1 = nums[0], sz = nums.size();
        for (int i = 1; i < sz; i++) {
            int new_rb_1 = rob_0 + nums[i];
            rob_0 = std::max(rob_0, rob_1);
            rob_1 = new_rb_1;
        }
        return rob_1;
    }
};

int main(int argc, char** argv) {
    Solution sol;

    return 0;
}