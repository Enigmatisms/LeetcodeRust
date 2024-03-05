#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <unordered_map>
#include <unordered_set>

using namespace std;

/**
 * 暴力法已经有想法了，应该是 O(n^2) 复杂度，估计 TLE
 * 我同时也想到了 O(nlogn) 的方法，实现起来可能复杂一些
 * 而我们能看出，（1）递推关系（2）递减关系（所以可以二分）
 * 我又是思路没问题，做题要做很久...
 * 思路不是最优的，但理论上来说，应该也不错... 最后可惜 TLE 了
 * 本题要用单调栈，单调栈没有思路
 * runtime: /
 * memory:  /
 */
class Solution {
public:
    vector<int> findMaximums(vector<int>& nums) {
        int num_num = static_cast<int>(nums.size());
        std::vector<int> result(num_num, 0);
        result[0] = nums[0];
        for (int i = 1; i < num_num; i++) {
            int cur_num = nums[i];
            int spos = num_num - (std::lower_bound(result.crbegin() + num_num - i, result.crend(), cur_num) - result.crbegin());
            if (spos == 0) {
                result[0] = cur_num;
                spos ++;
            }
            int min_elem = *std::min_element(nums.begin() + i - spos, nums.begin() + i);
            for (int j = spos; j <= i; j++) {
                min_elem  = std::min(min_elem, *(nums.begin() + i - j));
                if (cur_num >= min_elem) 
                    result[j] = std::max(min_elem, result[j]);
                else
                    result[j] = cur_num;
            }
        }
        return result;
    }
};

int main(int argc, char** argv) {
    Solution sol;
    std::vector<int> nums = {5, 1, 1, 5};
    sol.findMaximums(nums);
    return 0;
}