#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/**
 * 很多边界情况没想清楚，代码太丑了，还是要修修补补
 * (1) sptr + 1 是否会超界？只要看一种情况，长度为2的时候
 * (2) sptr == eptr (因为两端一直相等导致的)，需要特殊处理
 * 虽然写出来了，但是是在错了之后修改好的，所以看看官解
 * runtime: 100.00%
 * memory:  34.44%
 * 官方解答是真的很简洁啊
 */
class Solution {
public:
    int findMin(const vector<int>& nums) {
        int sptr = 0, eptr = static_cast<int>(nums.size()) - 1, mptr = 0;
        if (nums[sptr] < nums[eptr] || nums.size() == 1) return nums.front();
        while (sptr < eptr) {
            mptr = (sptr + eptr) >> 1;
            if (nums[eptr] > nums[mptr])
                eptr = mptr;
            else if (nums[eptr] < nums[mptr])
                sptr = mptr + 1;
            else
                eptr --;
        }
        return nums[eptr];
    }
    
    int findMin_mine(const vector<int>& nums) {
        int size = static_cast<int>(nums.size()), sptr = 0, eptr = size - 1, mptr = 0, min_val = 5000;
        if (nums[sptr] < nums[eptr] || nums.size() == 1) return nums.front();
        while (sptr < eptr) {      // first, find the rotated start
            // when nums[sptr] != nums[eptr], we will have enough information to continue
            // however, when nums[sptr] == nums[eptr], we need to skip these two situations
            int e_val = nums[eptr], s_val = nums[sptr];
            if (e_val == s_val) {
                min_val = std::min(min_val, e_val);
                sptr ++;
                eptr --;
                if (sptr == eptr)
                    min_val = std::min(min_val, nums[eptr]);
                continue;
            } else if (s_val < e_val) {
                return std::min(s_val, min_val);
            }
            mptr = (sptr + eptr) >> 1;
            if (mptr == sptr) break;
            if (nums[mptr] >= s_val) {
                sptr = mptr;
            }
            else
                eptr = mptr;
        }
        if (sptr == size - 1) return min_val;
        return std::min(min_val, nums[sptr + 1]);
    }
};

int main(int argc, char** argv) {
    Solution sol;

    return 0;
}