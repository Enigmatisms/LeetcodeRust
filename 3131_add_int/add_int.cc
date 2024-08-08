#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

/**
 * 本题就是：如果两个数组如果排序之后，对应位置的差值总相等，那么返回差就行
 * 由于本题保证了一定存在，所以不需要排序，找最大值就行。
 * runtime: 100.00%
 * memory:  10.12%
 */
class Solution {
public:
    static int addedInteger(const vector<int>& nums1, const vector<int>& nums2) noexcept {
        return (*std::max_element(nums2.begin(), nums2.end())) - 
               (*std::max_element(nums1.begin(), nums1.end()));
    }
};

int main(int argc, char** argv) {
    Solution sol;

    return 0;
}