#include "../ListNode.hpp"
class Solution {
public:
    // DFS 即可
    void recoverTree(TreeNode* root) const noexcept {
        TreeNode **prev_node = new TreeNode*, **err_node = new TreeNode*;
        *prev_node = nullptr;
        *err_node  = nullptr;
        bool ret = dfs_tree(root, prev_node, err_node);
        if (!ret) { // the last node should be swapped
            std::swap((*prev_node)->val, (*err_node)->val);
        }
        delete prev_node;
        delete err_node;
    }

    bool dfs_tree(TreeNode* root, TreeNode** prev_node, TreeNode** err_node) const noexcept {
        int cur_val = root->val;
        if (root->left) {
            bool ret = dfs_tree(root->left, prev_node, err_node);
            if (ret) return true;
        }
        if (*prev_node) {
            if (*err_node) {
                if (cur_val > (*err_node)->val) {
                    std::swap((*prev_node)->val, (*err_node)->val);
                    return true;
                }
            } else if ((*prev_node)->val > cur_val) {
                *err_node = *prev_node;
            }
        }
        *prev_node = root;
        if (root->right) {
            bool ret = dfs_tree(root->right, prev_node, err_node);
            if (ret) return true;
        }

        if (*err_node) {
            if (cur_val > (*err_node)->val) {
                std::swap((*prev_node)->val, (*err_node)->val);
                return true;
            }
        }
        return false;
    }
};

int main() {
    Solution sol;
    std::vector<TreeNode> nodes(4);
    nodes[0] = TreeNode(2, nullptr, nullptr);
    nodes[1] = TreeNode(1, nullptr, &nodes[0]);
    nodes[2] = TreeNode(4, &nodes[1], nullptr);
    nodes[3] = TreeNode(3, &nodes[2], nullptr);

    sol.recoverTree(&nodes[3]);
    return 0;
}