#include <iostream>
#include <vector>
#include <algorithm>
#include "../ListNode.hpp"

using namespace std;

/**
 * 这道题也是简单到爆炸
 * 层序遍历记录ID即可
 * runtime: 73.91%
 * memory:  23.23%
 */
class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        std::vector<std::pair<uint32_t, TreeNode*>> to_traverse;
        to_traverse.reserve(8);
        to_traverse.emplace_back(0, root);
        uint32_t max_width = 0;
        while (!to_traverse.empty()) {
            max_width = std::max(max_width, to_traverse.back().first - to_traverse.front().first);
            std::vector<std::pair<uint32_t, TreeNode*>> new_to_traverse;
            new_to_traverse.reserve(to_traverse.size() << 1);
            for (const auto& [node_id, node]: to_traverse) {
                if (node->left) {
                    new_to_traverse.emplace_back(2 * node_id, node->left);
                }
                if (node->right) {
                    new_to_traverse.emplace_back(2 * node_id + 1, node->right);
                }
            }
            to_traverse = std::move(new_to_traverse);
        }
        return max_width + 1;
    }
};

int main(int argc, char** argv) {
    Solution sol;

    return 0;
}