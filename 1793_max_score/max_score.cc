#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <limits>

using namespace std;

/**
 * 这题和接雨水有点像
 * k 在这里还是帮助我们的
 * 双指针，思路并不难。虽然 hard 题，但做起来还是顺手的
 * runtime: 79.76%
 * memory:  26.19%
 */
class Solution {
public:
    int maximumScore(vector<int>& nums, int k) {
        int num_len = nums.size(), sp = 0, ep = num_len - 1;
        int max_val = 0, cur_min = INT16_MAX;
        std::vector<int> left_mins(k + 1, INT16_MAX), right_mins(num_len - k, INT16_MAX);
        left_mins[0] = nums[k];
        right_mins[0] = nums[k];
        for (int i = k - 1; i >= 0; i--)
            left_mins[k - i]  = std::min(left_mins[k - i - 1], nums[i]);
        for (int i = k + 1; i < num_len; i++)
            right_mins[i - k] = std::min(right_mins[i - k - 1], nums[i]);
        cur_min = std::min(left_mins.back(), right_mins.back());
        int lval = left_mins.back(), rval = right_mins.back();
        while (true) {
            max_val = std::max(max_val, (ep - sp + 1) * cur_min);
            if (lval <= rval) {
                if (sp >= k) return max_val;
                ++ sp;
                lval = left_mins[k - sp];
            } else {
                if (ep <= k) return max_val;
                -- ep;
                rval = right_mins[ep - k];
            }
            cur_min = std::min(lval, rval);
        } 
        return max_val;
    }
};

int main(int argc, char** argv) {
    Solution sol;

    return 0;
}