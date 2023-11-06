#include <vector>
#include <iostream>

/**
 * 乍一看：在我看来这道题就是快排... 由于不需要stable sort以及是个排序问题
 * 但是其实这样会很低效：大多数都是最坏情况...
 * 双指针？双指针是否可以？
 * 我单双指针都可以拿到 100% runtime
 * memory: 48.59%
 */

class Solution {
public:
    // 单指针方法
    void sortColors(std::vector<int>& nums) const {
        if (nums.size() == 1) return;
        int num_0 = 0, num_1 = 0, num_2 = 0;
        for (int v: nums) {
            switch (v) {
            case 0: {num_0 ++; break;}
            case 1: {num_1 ++; break;}
            default:{num_2 ++; break;}
            }
        }
        auto ptr = nums.begin();
        for (; num_0 > 0; num_0--, ptr++)
            *ptr = 0;
        for (; num_1 > 0; num_1--, ptr++)
            *ptr = 1;
        for (; num_2 > 0; num_2--, ptr++)
            *ptr = 2;
    }

    // 双指针方法：交换！
    // 双指针的思想：个人感觉我的理解不是特别的透彻。
    // p0 一定存储最小的数字（p0 < p1），所以如果需要更换p0为p（发现p更小）
    // 首先需要将p0的值给p1（最大的先换给p0），p(最小的)再与p0换（最大的），实现p0最小，p1次之，p最大
    void sortColors2(std::vector<int>& nums) const {
        auto p0 = nums.begin(), p1 = nums.begin();
        for (auto p = nums.begin(); p != nums.end(); p++) {
            int cur_v = *p;
            switch (cur_v){
                case 0: {
                    if (p0 != p1)
                        std::swap(*p0, *p1);
                    if (p != p0 && p1 != p)
                        std::swap(*p, *p0);
                    p0 ++;
                    p1 ++;
                    break;
                }
                case 1: {
                    if (p != p1)
                        std::swap(*p, *p1);
                    p1 ++;
                }
                default: break;
            }
        }
    }
};

int main() {
    Solution sol;
    std::vector<int> colors{2, 0, 2, 1, 1, 0};
    sol.sortColors2(colors);
    for (int v: colors) {
        printf("%d, ", v);
    }
    printf("\n");
    return 0;
}