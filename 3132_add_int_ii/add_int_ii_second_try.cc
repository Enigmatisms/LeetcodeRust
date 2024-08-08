#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

/**
 * 第二次尝试，逻辑理顺了就好了
 * runtime: 67.47%
 * memory:  24.35%
 */
class Solution {
public:
    int minimumAddedInteger(vector<int>& nums1, vector<int>& nums2) {
        std::sort(nums1.begin(), nums1.end());
        std::sort(nums2.begin(), nums2.end());
        // 排序 + 枚举起点：碰到不相等的跳过去就行了
        int min_result = 1000, len_2 = nums2.size();
        // 必然出现以下三种情况之一（覆盖了全部）
        // 由于我们需要选择基准差，（1）如果不删第一个，则基准差为 nums2[0] - nums1[0]
        // (2) 如果删第一个，不删第二个，基准差：nums2[1] - nums1[0]
        // (3) 如果删前两个：nums2[2] - nums1[0]
        for (int i = 0; i <= 2; i++) {      
            int base_diff = nums2[0] - nums1[i];
            int ptr1 = i + 1, ptr2 = 1;
            for (; ptr2 < len_2 && ptr1 < len_2 + 2; ptr1 ++) {
                if (nums2[ptr2] - nums1[ptr1] == base_diff) {
                    ptr2 ++;
                    continue;
                }
            }
            if (ptr2 == len_2) {
                min_result = std::min(base_diff, min_result);
            }
        }
        return min_result;
    }
};

int main(int argc, char** argv) {
    Solution sol;

    return 0;
}