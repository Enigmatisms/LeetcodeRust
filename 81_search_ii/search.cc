#include <vector>
#include <iostream>
#include <algorithm>

/**
 * 这题能把我难住我是没想到的... 提交错了很多次... 考虑非常不周全，此题需要理解官方代码。
 * runtime: 47.19%
 * memory:  46.35%
 * 官方solution也不太行
*/

class Solution {
public:
    // 虽然最后过了，但我认为这个实现是有问题的。我的思路是：先找到rotation断点，此后判断在左右两段哪一段进行查找
    bool search(const std::vector<int>& nums, int target) const {
        if (nums.size() == 1) return (target == nums.front());
        int break_point = find_break_point(nums);
        if (target >= nums.front()) {
            return std::binary_search(nums.begin(), nums.begin() + break_point, target);
        } else {
            return std::binary_search(nums.begin() + break_point, nums.end(), target);
        }
    }

    int find_break_point(const std::vector<int>& nums) const {
        int sp = 0, ep = nums.size() - 1, mp = 0, old_val = nums.front();
        while ((nums[ep] == old_val && nums[sp] == old_val) && ep - sp > 1) {
            ep --;
            sp ++;
        }
        if (sp == ep) 
            return (nums[ep + 1] >= nums[ep]) ? ep : ep + 1;
        if (nums[sp] <= nums[ep]) {
            if (ep + 1 < nums.size()) {
                return nums[ep] > nums[ep + 1] ? ep + 1 : sp;
            }
            return ep + 1;
        }
        while (ep - sp > 1) {
            mp = (sp + ep) >> 1;
            int mid_val = nums[mp];
            if (mid_val >= nums[sp])
                sp = mp;
            else
                ep = mp;
        }
        return ep;
    }
};

class Solution2 {
public:
    // Leetcode 官方 solution (我修改了一下)
    bool search(const std::vector<int> &nums, int target) const {
        int n = nums.size();
        if (n == 1) {
            return nums.front() == target;
        }
        int l = 0, r = n - 1;
        while (l <= r) {
            int mid = (l + r) / 2;
            if (nums[mid] == target) {
                return true;
            }
            // 不是一开始缩小范围，而是在比较过程中，遇到不确定情况需要缩减范围
            if (nums[l] == nums[mid] && nums[mid] == nums[r]) {
                ++l;
                --r;
            } else if (nums[l] <= nums[mid]) { // 对有序区间进行检查，如果左半区间有序，则在左半区间内搜索。
                if (nums[l] <= target && target < nums[mid]) {
                    r = mid - 1;
                } else {
                    l = mid + 1;
                }
                // 我只能说官方代码非常不 intuitive
            } else {
                // 与 n-1 对比？ （官方代码原来这里写的是 target <= nums[n-1]），这就很诡异了
                // 这里的二分查找只在有序区间上进行，也即：左半有序比左半，右半有序比右半，无法判断则缩减区间
                if (nums[mid] < target && target <= nums[r]) {
                    l = mid + 1;
                } else {
                    r = mid - 1;
                }
            }
        }
        return false;
    }
};

int main(int argc, char ** argv) {
    Solution2 sol;
    std::vector<int> rotate1{4,5,6,6,7,7,7,7,0,0,1,2,4,4};
    std::vector<int> rotate2{4,4,4,4,4,4,4,4};
    std::vector<int> rotate3{1, 1, 1, 1, 1, 1, 1, 1, 1, 2, 1, 1, 1, 1};
    std::vector<int> rotate4{1, 1, 1, 2, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
    std::vector<int> rotate5{1, 0, 0, 0, 1};
    std::cout << sol.search(rotate1, 7) << std::endl;
    std::cout << sol.search(rotate1, -1) << std::endl;
    std::cout << sol.search(rotate1, 0) << std::endl;
    std::cout << sol.search(rotate1, 3) << std::endl;
    std::cout << sol.search(rotate2, 1) << std::endl;
    std::cout << sol.search(rotate2, 4) << std::endl;
    std::cout << sol.search(rotate3, 2) << std::endl;
    std::cout << sol.search(rotate4, 2) << std::endl;
    std::cout << sol.search(rotate5, 1) << std::endl;
    return 0;
}