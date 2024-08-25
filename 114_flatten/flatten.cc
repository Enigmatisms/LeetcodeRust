#include <iostream>
#include <vector>
#include "../ListNode.hpp"
using namespace std;

class Solution {
public:
    void flatten(TreeNode* root) const noexcept {
        if (!root) return;
        recursive_flatten(root);
    }

    // runtime: 100.00%, memory: 12.52%
    TreeNode* recursive_flatten(TreeNode* root) const noexcept {
        TreeNode* ret_leaf = nullptr;
        if (root->right)
            ret_leaf = recursive_flatten(root->right);
        if (root->left) {
            TreeNode* tmp_leave = recursive_flatten(root->left);
            if (!ret_leaf) ret_leaf = tmp_leave;
            tmp_leave->right = root->right;
            root->right = root->left;
            root->left  = nullptr;
        }
        if (!ret_leaf) ret_leaf = root;
        return ret_leaf;
    }

    // runtime: 100.00%, memory: 12.52%
    TreeNode* recursive_flatten2(TreeNode* root) const noexcept {
        TreeNode* tmp_right = root->right, *tmp_leave = nullptr;
        if (root->left) {
            tmp_leave = recursive_flatten2(root->left);
            root->right = root->left;
            root->left  = nullptr;
        }
        if (tmp_right) {
            TreeNode* ret_leaf = recursive_flatten2(tmp_right);
            if (tmp_leave)
                tmp_leave->right = tmp_right;
            if (ret_leaf) tmp_leave = ret_leaf;
        }
        if (!tmp_leave) tmp_leave = root;
        return tmp_leave;
    }
};

int main() {
  Solution sol;
  
  return 0; 
}