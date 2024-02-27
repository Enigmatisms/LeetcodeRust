#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
/**
 * 想到了滑动窗口思路就行，题目看错了... 我以为是等于
 * 题目看错导致后面浪费了时间查为什么不行以及改成正确的...
 * 我真是傻逼
 * runtime: 97.92%
 * memory:  38.66%
 */
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int nums_len = static_cast<int>(nums.size());
        int sptr = 0, eptr = 0, cur = 0, min_len = 1e5 + 1;
        while (sptr < nums_len) {
            if (eptr < nums_len && nums[eptr] > target) {
                return 1;
            };
            if (cur < target) {
                if (eptr >= nums_len) return min_len <= 1e5 ? min_len : 0;
                int val = nums[eptr];
                if (val == target) return 1;
                eptr += 1;
                cur  += val;
            } else if (cur > target) {
                min_len = std::min(min_len, eptr - sptr);
                cur  -= nums[sptr];
                sptr ++;
            } else {
                min_len = std::min(min_len, eptr - sptr);
                cur -= nums[sptr];
                sptr ++;
            }
        }
        return min_len <= 1e5 ? min_len : 0;
    }
};

int main(int argc, char** argv) {
    Solution sol;
    std::vector<int> vec = {1,2,3,4,5};
    int res = sol.minSubArrayLen(7, vec);
    return 0;
}