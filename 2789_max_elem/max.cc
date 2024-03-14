#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/**
 * 一个观察：递增序列可以合并。最坏情况：
 * 一个递减序列 + 一个超大元素在末尾，递减序列的起始元素小于末尾超大元素
 * 则实际上这整个序列也是可以合并的
 * 很简单嘛... O(n) 遍历 + O(1) 空间就能做 
 * 好秒了
 * runtime: 87.44%
 * memory:  42.71%
 */
class Solution {
public:
    long long maxArrayValue(vector<int>& nums) {
        int num_len = nums.size();
        long long max_val = nums.back();
        for (int i = num_len - 1; i >= 1; ) {
            long long merge_val = nums[i];
            bool can_merge = true;
            for (i = i - 1; i >= 0; i--) {
                long long num = nums[i];
                if (merge_val >= num) {
                    merge_val += num;
                } else {
                    max_val = std::max(num, max_val);
                    can_merge = false;
                    break;
                }
            }
            if (can_merge)
                return merge_val;
        }
        return max_val;
    }
};

int main(int argc, char** argv) {
    Solution sol;

    return 0;
}