#include <iostream>
#include <vector>
#include <algorithm>
#include "../ListNode.hpp"

using namespace std;

/**
 * 
 * runtime: 88.27%
 * memory:  71.30%
 */
class Solution {
public:
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        std::vector<TreeNode*> dfs_stack = {cloned};
        int tval = target->val;
        while (dfs_stack.empty() == false) {
            auto node = dfs_stack.back();
            dfs_stack.pop_back();
            if (node->val == tval)
                return node;
            if (node->right)
                dfs_stack.push_back(node->right);
            if (node->left)
                dfs_stack.push_back(node->left);
        }
        return nullptr;
    }
};

int main(int argc, char** argv) {
    Solution sol;

    return 0;
}