#include <iostream>
#include <vector>
#include <algorithm>
#include "../ListNode.hpp"

using namespace std;

/**
 * 
 * runtime: 100.00% (recursive)
 * memory:  5.63%   (recursive) 25.75% (iterative)
 */
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        if (!root) return {};
        std::vector<TreeNode*> stack = {root};
        std::vector<int> result;
        while (stack.empty() == false) {
            auto top_node = stack.back();
            stack.pop_back();
            result.push_back(top_node->val);
            if (top_node->left)  stack.push_back(top_node->left);
            if (top_node->right) stack.push_back(top_node->right);
        }
        std::reverse(result.begin(), result.end());
        return result;
    }

    vector<int> postorderTraversal2(TreeNode* root) {
        if (!root) return {};
        std::vector<int> results;
        recursive_solve2(results, root);
        return results;
    }

    void recursive_solve2(std::vector<int>& result, TreeNode* current) const {
        if (current->left) recursive_solve2(result, current->left);
        if (current->right) recursive_solve2(result, current->right);
        result.push_back(current->val);
    }
};

int main(int argc, char** argv) {
    Solution sol;

    return 0;
}