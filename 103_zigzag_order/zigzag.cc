#include <memory>
#include "../ListNode.hpp"

/**
 * 并没有什么难点
 * runtime: 61.15%
 * memory:  80.33%
*/
class Solution {
public:
    std::vector<std::vector<int>> zigzagLevelOrder(TreeNode* root) {
        std::vector<std::vector<int>> results;
        if (!root) return results;
        std::unique_ptr<std::vector<TreeNode*>> bfs_stack = std::make_unique<std::vector<TreeNode*>>();
        bfs_stack->emplace_back(root);
        for (int i = 0; bfs_stack->empty() == false; i++) {
            std::unique_ptr<std::vector<TreeNode*>> new_stack = std::make_unique<std::vector<TreeNode*>>();
            new_stack->reserve(bfs_stack->size() << 1);
            results.emplace_back();
            for (auto it = bfs_stack->crbegin(); it != bfs_stack->crend(); it++) {
                if (*it == nullptr) continue;
                results.back().emplace_back((*it)->val);
                if (i & 1) {
                    new_stack->emplace_back((*it)->right);
                    new_stack->emplace_back((*it)->left);
                } else {
                    new_stack->emplace_back((*it)->left);
                    new_stack->emplace_back((*it)->right);
                }
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