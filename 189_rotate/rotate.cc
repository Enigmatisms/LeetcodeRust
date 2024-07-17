#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/**
 * 旋转的优雅做法
 * runtime: 41.04%
 * memory:  44.24%
 */
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int size = nums.size();
        k %= size;
        if (k == 0) return;
        reverse(nums, 0, size);
        reverse(nums, 0, k);
        reverse(nums, k, size);
    }

    void reverse(vector<int>& nums, int start, int end) {
        for (int i = start, j = end - 1; i < j; i++, j--) {
            std::swap(nums[i], nums[j]);
        }
    }
};

int main(int argc, char** argv) {
    Solution sol;

    return 0;
}