#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <unordered_map>
#include <unordered_set>
#include "../ListNode.hpp"

using namespace std;

/**
 * runtime: 91.95%
 * memory:  26.55%
 */
class Solution {
public:
    int countNodes(TreeNode* root) {
        if (!root) return 0;
        int node_cnt = 1;
        std::vector<TreeNode*> stack = {root};
        while (stack.empty() == false) {
            std::vector<TreeNode*> new_stack;
            new_stack.reserve(stack.size());
            for (auto node: stack) {
                if (node->left) {
                    ++ node_cnt;
                    new_stack.push_back(node->left);
                }
                if (node->right) {
                    ++ node_cnt;
                    new_stack.push_back(node->right);
                }
            }
            stack = std::move(new_stack);
        }
        return node_cnt;
    }
};

int main(int argc, char** argv) {
    Solution sol;

    return 0;
}