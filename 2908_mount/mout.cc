#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <unordered_map>
#include <unordered_set>

using namespace std;

/**
 * 后缀和优化 ---> 没有进一步去想前缀和... 想到前缀和就变成 O(n) 了
 * 只能说做题还是别急，看看有没有优化方案
 * runtime: 71.96%
 * memory:  29.63%
 */
class Solution {
public:
    // TMD 又看错题了
    int minimumSum(vector<int>& nums) {
        int num_len = nums.size(), sptr = 0, eptr = 1, min_sum = INT32_MAX;
        if (num_len < 3) return -1;
        std::vector<int> suffix_min(num_len);
        suffix_min.back() = nums.back();
        for (int i = num_len - 2; i >= 0; i--)
            suffix_min[i] = std::min(suffix_min[i + 1], nums[i]);
        // O(n^2) 时间复杂度
        for (int i = 0; i < num_len - 2; i++) {
            int s_num = nums[i];
            for (int j = i + 1; j < num_len - 1; j++) {
                int num = nums[j], suff_min = suffix_min[j + 1];
                if (num > s_num && suff_min < num)
                    min_sum = std::min(min_sum, suff_min + num + s_num);
            }
        }
        return min_sum == INT32_MAX ? -1 : min_sum;
    }

    // TMD 又看错题了: 这是连续三元组，滑动窗口
    int minimumSum_false(vector<int>& nums) {
        int num_len = nums.size(), sptr = 0, eptr = 1, min_sum = INT32_MAX;
        if (num_len < 3) return -1;
        while (eptr < num_len) {
            int e_num = nums[eptr], s_num = nums[sptr];
            if (e_num > s_num) {
                if (eptr + 1 >= num_len) return min_sum == INT32_MAX ? -1 : min_sum;
                int next_num = nums[++eptr];
                if (next_num < e_num) {
                    min_sum = std::min(s_num + e_num + next_num, min_sum);
                    sptr = eptr ++;
                } else if (next_num > e_num) {
                    ++ sptr;
                } else {    // equal (eptr + 1, sptr = eptr - 1)
                    sptr = eptr ++;
                }
            } else {
                sptr = eptr ++;
            }
        }
        return min_sum == INT32_MAX ? -1 : min_sum;
    }
};

int main(int argc, char** argv) {
    Solution sol;

    return 0;
}