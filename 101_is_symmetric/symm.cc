#include <memory>
#include "../ListNode.hpp"

/**
 * 并没有什么难点
 * 我特意没写递归版本的
 * runtime: 76.86%
 * memory:  14.07%
*/
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        std::unique_ptr<std::vector<TreeNode*>> bfs_stack = std::make_unique<std::vector<TreeNode*>>();
        bfs_stack->emplace_back(root->left);
        bfs_stack->emplace_back(root->right);
        while (bfs_stack->empty() == false) {
            size_t full_size = bfs_stack->size(), half_size = full_size >> 1;
            for (size_t i = 0; i < half_size; i++) {
                TreeNode *front = (*bfs_stack)[i], *back = (*bfs_stack)[full_size - 1 - i];
                if ((front == nullptr) ^ (back == nullptr)) return false;
                if (front == nullptr) continue;
                if (front->val != back->val) return false;
            }
            std::unique_ptr<std::vector<TreeNode*>> new_stack = std::make_unique<std::vector<TreeNode*>>();
            new_stack->reserve(full_size << 1);
            for (const auto& ptr: *bfs_stack) {
                if (ptr == nullptr) continue;
                new_stack->emplace_back(ptr->left);
                new_stack->emplace_back(ptr->right);
            }
            bfs_stack = std::move(new_stack);
        }
        return true;
    }
};