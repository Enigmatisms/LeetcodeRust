#include <iostream>
#include <vector>
#include <algorithm>
#include "../ListNode.hpp"

using namespace std;

/**
 * 这道题不算中等吧，分明就是简单题
 * runtime: 88.90%
 * memory:  16.12%
 */
class Solution {
public:
    inline int goodNodes(TreeNode* root) const noexcept {
        return dfs_with_max(root, root->val);
    }

    int dfs_with_max(TreeNode* node, int maxv) const noexcept {
        if (!node) return 0;
        bool v = node->val >= maxv;
        maxv = v ? node->val : maxv;
        return dfs_with_max(node->left, maxv) + dfs_with_max(node->right, maxv) + v;
    }
};

int main(int argc, char** argv) {
    Solution sol;

    return 0;
}