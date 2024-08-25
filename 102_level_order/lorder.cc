#include <memory>
#include "../ListNode.hpp"

/**
 * 并没有什么难点
 * runtime: 87.07%
 * memory:  46.58%
*/
class Solution {
public:
    std::vector<std::vector<int>> levelOrder(TreeNode* root) {
        std::vector<std::vector<int>> results;
        if (!root) return results;
        std::unique_ptr<std::vector<TreeNode*>> bfs_stack = std::make_unique<std::vector<TreeNode*>>();
        bfs_stack->emplace_back(root);
        while (bfs_stack->empty() == false) {
            std::unique_ptr<std::vector<TreeNode*>> new_stack = std::make_unique<std::vector<TreeNode*>>();
            new_stack->reserve(bfs_stack->size() << 1);
            results.emplace_back();
            for (const auto& ptr: *bfs_stack) {
                if (ptr == nullptr) continue;
                results.back().emplace_back(ptr->val);
                new_stack->emplace_back(ptr->left);
                new_stack->emplace_back(ptr->right);
            }
            if (new_stack->empty()) {
                results.pop_back();
                break;
            } else {
                bfs_stack = std::move(new_stack);
            }
        }
        return results;
    }
};