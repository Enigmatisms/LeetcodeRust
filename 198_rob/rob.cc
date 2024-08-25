#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <unordered_map>
#include <unordered_set>

using namespace std;

/**
 * 这道题很容易出现两个情况：
 *  1. 脑子一热直接递归。递归可以很好地产生思路，没问题但效率太低，但假设你发现递归过程中某一个值可能被重复计算，就说明需要DP了
 *  2. 考虑的情况不足。[2, 1, 1, 2] 这种情况无法直接通过保存上两个结果做对，需要上三个结果。
 * 我的思路还不太一样... 其实保存两个子问题结果即可，我的思路... 还比较奇怪...
 * （1）最优的思路1 (真正写出子问题，而不是策略推进)
 * runtime: 100.00%
 * memory:  29.62%
 * （2）这是思路2
 * runtime: 100.00%
 * memory:  35.09%
 */
class Solution {
public:
    int rob(const vector<int>& nums) const {
        int length = static_cast<int>(nums.size());
        if (length == 1) return nums.front();
        int rob_a = 0, rob_b = nums.front();
        for (int cnt = 1; cnt < length; cnt ++) {
            int cur = std::max(nums[cnt] + rob_a, rob_b);
            rob_a = rob_b;
            rob_b = cur;
        }
        return rob_b;
    }

    int rob2(const vector<int>& nums) const {
        int length = static_cast<int>(nums.size());
        switch (length) {
            case 2: return std::max(nums.front(), nums.back());
            case 1: return nums.front();
            default: break;
        }
        int rob_c = nums.back(), 
            rob_b = *(nums.crbegin() + 1),
            rob_a = *(nums.crbegin() + 2) + rob_c;
        for (int cnt = 3; cnt < length; cnt ++) {
            int cur = std::max(nums[length - cnt - 1] + rob_c, nums[length - cnt - 1] + rob_b);
            cur     = std::max(cur, rob_a);
            rob_c = rob_b;
            rob_b = rob_a;
            rob_a = cur;
        }
        return std::max(rob_a, rob_b);
    }

    int rob3(vector<int>& nums) {
        return recursive_rob(nums, 0);
    }

    // 这样不算完全的动态规划吧？因为这复杂度还是会比较高。我知道这可以做出来，但效果估计不怎么样
    int recursive_rob(const std::vector<int>& nums, int index) const {
        if (index >= nums.size()) return 0;
        return std::max(
            nums[index] + recursive_rob(nums, index + 2),
            recursive_rob(nums, index + 1)
        );
    }
};

int main(int argc, char** argv) {
    Solution sol;

    return 0;
}