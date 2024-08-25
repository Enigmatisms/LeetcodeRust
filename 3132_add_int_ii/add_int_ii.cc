#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

/**
 * 是否可以这样讨论？
 * 讨论最大和最小。最大和最小被删除的情况只有四种：（1）都删（2）都不删（3）删最大（4）删最小
 * 都不删或者删一个... 无法确定剩下的怎么删，但由于定死了只要去除两个不相同的，即可
 * 
 * 这是这道题我的初始解
 * 这道题我拉了,557/560
 * 对“最小”的考虑有所欠缺。所枚举的事件有问题
 * runtime: 
 * memory: 
 */
class Solution {
public:
    int minimumAddedInteger(vector<int>& nums1, vector<int>& nums2) {
        std::sort(nums1.begin(), nums1.end());
        std::sort(nums2.begin(), nums2.end());
        int dmax = nums2.back() - nums1.back(), dmin = nums2.front() - nums1.front();
        if (dmax == dmin) {
            int diff = nums2[0] - nums1[1];
            for (size_t i = 1; i < nums2.size(); i++) {
                if (nums2[i] - nums1[i + 1] != diff) return dmin;
            }
            return diff;
        } else {
            // 先假设删除最小的而最大的存留：从最大的往前走，遇到的第一个不一致的对，删除 nums1 中相应结果后，如果后续与 dmax 一致，则成立
            auto ptr1 = nums1.crbegin() + 1, ptr2 = nums2.crbegin() + 1;        // 跳过最大的（最后一个数）
            bool skipped = false;
            for (; ptr2 != nums2.crend(); ptr1 ++) {
                if ((*ptr2) - (*ptr1) == dmax) {
                    ptr2 ++;
                    continue;
                }
                if (!skipped) {
                    skipped = true;
                } else {                // 已经出现一次不相同了，再次出现只能说明最小值不应该删
                    // 已经判定知 dmax 应该被删除，现在判定 dmin 是否要被删除
                    break;
                }
            }
            if (ptr2 == nums2.crend()) return dmax;

            auto new_ptr1 = nums1.begin() + 1, new_ptr2 = nums2.begin() + 1;        // 跳过最小的
            skipped = false;
            for (; new_ptr2 != nums2.end(); new_ptr1 ++) {
                if ((*new_ptr2) - (*new_ptr1) == dmin) {
                    new_ptr2 ++;
                    continue;
                }
                if (!skipped) {
                    skipped = true;
                } else {                // 已经出现一次不相同了，再次出现只能说明最小值不应该删
                    // 已经判定知 dmin 也应该被删除，现在判定 dmin 是否要被删除
                    break;
                }
            }
            if (new_ptr2 == nums2.end()) return dmin;
            return nums2[0] - nums1[1];
        }
        return dmax;
    }
};

int main(int argc, char** argv) {
    Solution sol;

    return 0;
}