#include <iostream>
#include <vector>
#include <algorithm>
#include "../ListNode.hpp"

using namespace std;

/**
 * 秒杀，层序遍历罢了
 * runtime: 100.00%
 * memory:  69.86%
 */
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        std::vector<TreeNode*> to_traverse;
        std::vector<int> results;
        to_traverse.reserve(8);
        if (root)
            to_traverse.emplace_back(root);
        results.reserve(8);
        while (!to_traverse.empty()) {
            results.push_back(to_traverse.back()->val);
            std::vector<TreeNode*> new_to_traverse;
            new_to_traverse.reserve(to_traverse.size() << 1);
            for (const auto& node: to_traverse) {
                if (node->left) {
                    new_to_traverse.emplace_back(node->left);
                }
                if (node->right) {
                    new_to_traverse.emplace_back(node->right);
                }
            }
            to_traverse = std::move(new_to_traverse);
        }
        return results;
    }
};

int main(int argc, char** argv) {
    Solution sol;

    return 0;
}