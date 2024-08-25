#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <unordered_map>
#include <unordered_set>

using namespace std;

/**
 * 这道破题，看错了两遍题，第一遍以为是前后交替出现就行，结果发现|差|要是1
 * 第二遍没看见第一次差要是正的...
 * 这种题目... 思路很简单，但是写起来总是会有一些边缘情况出问题，还秒不了
 * 首先看清题啊！！！
 * 操 
 * 
 * 所以思路：先记录 diff, 并看当前是否已经开始了一个交替数组，如果没有开启，开启条件是 diff = 1
 * 如果开启了，就只需要比较下一个与当前是否是互反关系，不是的话不管什么情况，都重新开始统计
 * 注意边界：当只有两个的时候，以及最后两个是新开启的时候
 * runtime: 95.51%
 * memory:  87.41%
 */
class Solution {
public:
    int alternatingSubarray(vector<int>& nums) {
        int num_len = nums.size(), diff = nums[1] - nums[0], cur_len = -1, max_len = -1;
        for (int i = 1; i + 1 < num_len; i++) {
            if (cur_len == -1) {
                if (diff != 1) {
                    diff = nums[i + 1] - nums[i];
                    continue;
                }
                cur_len = 2;
            }
            int new_diff = nums[i + 1] - nums[i];
            if (new_diff != -diff) {
                max_len = std::max(max_len, cur_len);
                cur_len = -1;
                diff = new_diff;
            } else {
                cur_len ++;
                diff = new_diff;
            }
        }
        if (diff == 1)
            max_len = std::max(max_len, 2);
        return std::max(max_len, cur_len);
    }
};

int main(int argc, char** argv) {
    Solution sol;

    return 0;
}