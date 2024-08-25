#include <vector>
#include <iostream>
#include <unordered_map>
#include "../ListNode.hpp"

/**
 * 感冒做题效率真高（呕）
 * runtime: 97.94%
 * memory:  76.57%
*/

class Solution {
std::unordered_map<int, int> mapping;
public:
    TreeNode* buildTree(std::vector<int>& inorder, std::vector<int>& postorder) {
        for (int i = 0; i < inorder.size(); i++)
            mapping[inorder[i]] = i;
        return recursive_build(inorder, postorder, 0, 0, postorder.size() - 1);
    }

    TreeNode* recursive_build(const std::vector<int>& inorder, const std::vector<int>& postorder, int i_s, int p_s, int p_e) const {
        int root_val = postorder[p_e], inorder_idx = (*mapping.find(root_val)).second;
        int left_p_e = inorder_idx - i_s - 1 + p_s, right_p_s = left_p_e + 1;
        auto new_node = new TreeNode(root_val, nullptr, nullptr);
        if (left_p_e >= p_s)
            new_node->left = recursive_build(inorder, postorder, i_s, p_s, left_p_e);
        if (right_p_s + 1 <= p_e)
            new_node->right = recursive_build(inorder, postorder, inorder_idx + 1, right_p_s, p_e - 1);
        return new_node;
    }
};

int main(int argc, char** argv) {
    Solution sol;

    return 0;
}