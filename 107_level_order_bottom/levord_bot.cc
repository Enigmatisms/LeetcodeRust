#include <iostream>
#include <vector>
#include <algorithm>
#include "../ListNode.hpp"

/**
 * runtime: 71.79%
 * memory:  11.90%
*/

class Solution {
public:
    std::vector<std::vector<int>> levelOrderBottom(TreeNode* root) const {
        if (!root) return {};
        std::vector<TreeNode*> stack = {root};
        std::vector<std::vector<int>> results;
        while (stack.empty() == false) {
            std::vector<TreeNode*> new_stack;
            std::vector<int> result;
            for (const auto& node: stack) {
                result.push_back(node->val);
                if (node->left) new_stack.push_back(node->left);                
                if (node->right) new_stack.push_back(node->right);                
            }
            results.push_back(result);
            stack = std::move(new_stack);
        }
        std::reverse(results.begin(), results.end());
        return results;
    }
};

int main() {
  Solution sol;
  
  return 0; 
}