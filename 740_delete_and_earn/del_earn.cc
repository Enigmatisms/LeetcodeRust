#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <unordered_map>
#include <unordered_set>

using namespace std;

/**
 * 本题没有明显的子问题（直接上手构建是构建不出来的）
 * 本题需要将问题转化为 198 (rob) 问题
 * runtime: 100.00%
 * memory:  52.19%
 */
class Solution {
public:
    int deleteAndEarn(const vector<int>& nums) {
        int max_elem = nums.front(), min_elem = nums.front();
        for (int num: nums) {
            if (num < min_elem) min_elem = num;
            else if (num > max_elem) max_elem = num;
        }
        std::vector<int> to_rob(max_elem - min_elem + 1);
        for (int num: nums)
            to_rob[num - min_elem] += num;
        return rob(to_rob);
    }
private:
    // leetcode 198 rob
    int rob(const std::vector<int>& nums) const {
        int length = static_cast<int>(nums.size());
        if (length < 2) return nums.front();
        int rob_a = 0, rob_b = nums.front();
        for (int cnt = 1; cnt < length; cnt ++) {
            int cur = std::max(nums[cnt] + rob_a, rob_b);
            rob_a = rob_b;
            rob_b = cur;
        }
        return rob_b;
    }
};

int main(int argc, char** argv) {
    Solution sol;

    return 0;
}