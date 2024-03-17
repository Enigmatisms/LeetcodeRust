#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/**
 * 注意本问题中不存在连续相等的情形，也就是不用担心有 3, 5, 5, 4 这样的情况使得
 * 搜索失败. 本题 logn 思路不那么好想（实现起来有点恶心），n 的话随便写...
 * 不能满足题目要求的 O(logn) 写法我就不在这里写了
 * 因为只需要求一个峰值，故可以贪心：遇到上坡（右）就一直走，抛弃上坡前所有的部分
 * 遇到下坡就一直往反方向走
 * runtime: 71.18%
 * memory:  21.07% 
 */
class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int num_size = nums.size();
        if (num_size == 1) return 0;
        int sptr = 0, eptr = num_size - 1;
        while (sptr != eptr) {
            int mptr = (sptr + eptr) >> 1, mval = nums[mptr];
            // check if current is peak
            bool gt_next = mval > nums[mptr + 1];
            if (gt_next && (mptr == 0 || mval > nums[mptr - 1]))
                return mptr;
            if (gt_next)
                eptr = mptr;
            else
                sptr = mptr + 1;
        }
        return sptr;
    }
};

int main(int argc, char** argv) {
    Solution sol;

    return 0;
}