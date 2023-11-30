#include "../ListNode.hpp"

/**
 * 根本没测试过，就一遍过
 * runtime: 100.00%
 * memory:  66.67%
*/

class Solution {
public:
    std::vector<int> inorderTraversal(TreeNode* root) const {
        std::vector<int> results;
        if (root)
            recursive_traversal(root, results);
        return results;
    }

    void recursive_traversal(TreeNode* node, std::vector<int>& vals) const {
        if (node->left)
            recursive_traversal(node->left, vals);
        vals.push_back(node->val);
        if (node->right)
            recursive_traversal(node->right, vals);
    }
};
