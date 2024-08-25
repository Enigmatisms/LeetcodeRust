#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <unordered_map>
#include <unordered_set>
#include "../ListNode.hpp"

using namespace std;

/**
 * runtime: 81.60%
 * memory:  28.80%
 */
class Solution {
public:
    long long kthLargestLevelSum(TreeNode* root, int k) {
        std::vector<TreeNode*> stack = {root};
        std::vector<long long> level_sums; 
        while (!stack.empty()) {
            std::vector<TreeNode*> new_stack;
            long long level_sum = 0;
            for (TreeNode* node: stack) {
                level_sum += node->val;
                if (node->left) new_stack.push_back(node->left);
                if (node->right) new_stack.push_back(node->right);
            }
            level_sums.emplace_back(level_sum);
            stack = std::move(new_stack);
        }
        if (k > level_sums.size()) return -1;
        size_t offset = level_sums.size() - k;
        std::nth_element(level_sums.begin(), level_sums.begin() + offset, level_sums.end());
        return *(level_sums.begin() + offset);
    }
};

int main(int argc, char** argv) {
    Solution sol;

    return 0;
}