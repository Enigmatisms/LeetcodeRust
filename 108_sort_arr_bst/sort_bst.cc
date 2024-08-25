#include <iostream>
#include <vector>
#include "../ListNode.hpp"
using namespace std;

/**
 * runtime: 91.41%
 * memor:   93.73%
*/

class Solution {
public:
    TreeNode* sortedArrayToBST(const vector<int>& nums) const {
        return recursive_build(nums, 0, nums.size());
    }

    TreeNode* recursive_build(const vector<int>& nums, int start, int end) const {
        if (start >= end) return nullptr;
        if (start == end - 1)
            return new TreeNode(nums[start], nullptr, nullptr);
        int center_idx = (start + end) >> 1;
        auto res = new TreeNode(nums[center_idx], nullptr, nullptr);
        res->left = recursive_build(nums, start, center_idx);
        res->right = recursive_build(nums, center_idx + 1, end);
        return res;
    }
};

int main() {
  Solution sol;
  
  return 0; 
}