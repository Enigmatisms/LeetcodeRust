#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void print_vec(const std::vector<int>& vec) {
    std::cout << "[";
    for (auto v: vec) {
        std::cout << v << ", ";
    }
    std::cout << "]" << std::endl;
}

/**
 * 这道题应该是用 partition 相关的算法
 * 我们把大于某一数放在某区域右边，
 * 小于某一数放在左边，中间留下的是等于的
 * 就看 k，如果 k 在 大于区，接下来就递归地在大于区查找
 * 其他类推
 * runtime: 81.52%
 * memory:  49.00%
 */
class Solution {
public:
    int quick_select(vector<int>& nums, int start, int end, int k) {
        if (start == end) return nums[k];
        int sptr = start - 1, eptr = end + 1;
        int val = nums[start];
        while (sptr < eptr) {
            do {
                ++ sptr;
            } while (nums[sptr] < val);     // 如果 sptr (左指针) 指向的数据已经小于 val 了，就没必要处理此数据了，跳过
            do {
                -- eptr;
            } while (nums[eptr] > val);     // 同理
            if (sptr >= eptr) break;
            std::swap(nums[sptr], nums[eptr]);      // 因为指针停下来的地方一定不满足 nums[sptr] < val 以及 nums[eptr] > val
            // 如果存在等于也无所谓
        }
        // printf("Start: %d, end: %d, k: %d, sptr: %d, eptr: %d. ", start, end, k, sptr, eptr);
        // print_vec(nums);
        // 到这里时，我们已经分好了 sptr 和 eptr
        if (eptr >= k) {       // k 在小于区
            return quick_select(nums, start, eptr, k);
        } else {
            return quick_select(nums, eptr + 1, end, k);
        }
    }

    int findKthLargest(vector<int>& nums, int k) {
        int size = nums.size();
        return quick_select(nums, 0, size - 1, size - k);
    }
};


int main(int argc, char** argv) {
    Solution sol;
    std::vector<std::vector<int>> tests = {
        {7,6,5,4,3,2,1},
        {3,2,1,5,6,4},
        {3,2,3,1,2,4,5,5,6},
    };
    std::vector<int> ks = {2, 2, 5};
    for (size_t i = 0; i < 3; i++) {
        std::cout << "Test " << i << std::endl;
        std::cout << sol.findKthLargest(tests[i], ks[i]) << std::endl;
    }
    return 0;
}