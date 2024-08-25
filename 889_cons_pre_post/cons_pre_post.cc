#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <unordered_map>
#include <unordered_set>
#include "../ListNode.hpp"

using namespace std;

/**
 * 思路很简单：后序遍历中根一定在左右子树后面，用相对位置关系可以确定
 * runtime: 96.35%
 * memory:  44.65%
 */
class Solution {
private:
    std::unordered_map<int, uint8_t> pos_mapping;
public:
    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
        if (preorder.size() == 1) return new TreeNode(preorder.front(), nullptr, nullptr);
        for (size_t i = 0; i < postorder.size(); i++)
            pos_mapping[postorder[i]] = static_cast<uint8_t>(i);
        size_t index = 0;
        return build_tree_recursive(preorder, index);
    }

    TreeNode* build_tree_recursive(const vector<int>& preorder, size_t& index) {
        if (index >= preorder.size()) return nullptr;
        int current_val = preorder[index];
        TreeNode* this_node = new TreeNode(current_val, nullptr, nullptr);
        index++;
        if (index >= preorder.size()) return this_node;
        int next_val = preorder[index];
        uint8_t current_pos = pos_mapping[current_val];
        if (pos_mapping[next_val] < current_pos)
            this_node->left = build_tree_recursive(preorder, index);
        if (index >= preorder.size()) return this_node;
        next_val = preorder[index];
        if (pos_mapping[next_val] < current_pos)
            this_node->right = build_tree_recursive(preorder, index);
        return this_node;
    }
};

int main(int argc, char** argv) {
    Solution sol;

    return 0;
}