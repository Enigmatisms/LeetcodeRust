#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <unordered_map>
#include <unordered_set>

using namespace std;

/**
 * 这道题也确实能直接暴力... 但是复杂度太高
 * 我的解法还是暴力。这道题官方解答是归并排序：
 * 拆开后升序排序。在组合的时候，查需要被输入的两个数组。
 * (1) 如果右数组.back() 小于 左数组.front()，则俩size相乘
 * (2) 否则左边开始二分查找右边（两个指针），后依次累加
 * 
 * 归并会快一些
 */
class Solution {
public:
    int InversePairs(vector<int>& nums) {
        std::vector<int> sorted_nums(nums.begin(), nums.end());
        std::sort(sorted_nums.begin(), sorted_nums.end());
        long long result = 0;
        for (int num: nums) {
            auto it = std::lower_bound(sorted_nums.begin(), sorted_nums.end(), num);
            result += it - sorted_nums.begin();
            sorted_nums.erase(it);
        }
        return result % 1000000007;
    }
};

int main(int argc, char** argv) {
    Solution sol;

    return 0;
}