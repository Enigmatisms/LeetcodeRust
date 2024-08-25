#include <iostream>
#include <vector>
#include <algorithm>
#include "../../ListNode.hpp"

using namespace std;

/**
 * 毕竟是简单题
 * runtime:
 * memory:
 */
class Solution {
public:
    int lowestCommonAncestor(TreeNode* root, int p, int q) {
        // write code here
        std::vector<TreeNode*> nodes = {root};
        std::unordered_map<int, TreeNode*> fathers;
        fathers[root->val] = nullptr;
        while (nodes.empty() == false) {
            TreeNode* node = nodes.back();
            nodes.pop_back();
            if (node->val == p || node->val == q) {
                int target = node->val == p ? q : p, no_access = -1;
                while (dfs_search(node, target, no_access) == false) {
                    no_access = node->val;
                    node = fathers[no_access];
                }
                return node->val;
            } else {
                if (node->left)  {
                    nodes.push_back(node->left);
                    fathers[node->left->val] = node;
                }
                if (node->right) {
                    nodes.push_back(node->right);
                    fathers[node->right->val] = node;
                }
            }
        }
        return -1;
    }       

    bool dfs_search(TreeNode* cur, int target, int no_access = -1) {
        bool result = false;
        if (cur->left) {
            int val = cur->left->val;
            if (val == target) return true;
            if (val != no_access)
                result = dfs_search(cur->left, target, no_access);
        }
        if (result) return true;
        if (cur->right) {
            int val = cur->right->val;
            if (val == target) return true;
            if (val != no_access)
                result = dfs_search(cur->right, target, no_access);
        }
        return result;
    }
};

int main(int argc, char** argv) {
    Solution sol;

    return 0;
}