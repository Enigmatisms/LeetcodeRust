#include <vector>
#include <iostream>
#include "../ListNode.hpp"

/**
 * 这道题花了我一分钟想与实现... 太简单了
 * runtime: 100%
 * memory:  99.96%
*/

class Solution {
public:
    int maxDepth(TreeNode* root) const noexcept {
        return recursive_dfs(root);
    }

    int recursive_dfs(TreeNode* root) const noexcept {
        if (root == nullptr)
            return 0;
        int d1 = recursive_dfs(root->left) + 1;
        int d2 = recursive_dfs(root->right) + 1;
        return std::max(d1, d2);
    }
};

int main(int argc, char** argv) {
    Solution sol;

    return 0;
}