#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include "../ListNode.hpp"

using namespace std;

/**
 * 第一种做法完全就是错的... 而且还很繁琐，这道题看起来很简单对不对？
 * 335/336 通过用例，最后一个用例爆炸了
 * 如果最近的叶结点跨了超过一个父节点，我这个方法就会炸，虽然很好想但没有一点用
 * runtime: /
 * memory:  /
 */
class Solution {
public:
    int findClosestLeaf(TreeNode* root, int k) {
        std::vector<TreeNode*> stack = {root};
        while (stack.empty() == false) {
            auto top = stack.back();
            stack.pop_back();
            int left_min = 0, right_min = 0, l_level = 1001, r_level = 1001;
            if (top->val != k) {
                if (top->left && top->left->val == k) {
                    left_min = closest_subtree_leaf(top->left, l_level);
                    if (top->right) 
                        right_min = closest_subtree_leaf(top->right, r_level);
                    return l_level <= r_level + 2 ? left_min : right_min;
                } else if (top->right && top->right->val == k) {
                    right_min = closest_subtree_leaf(top->right, r_level);
                    if (top->left) 
                        left_min = closest_subtree_leaf(top->left, l_level);
                    return r_level <= l_level + 2 ? right_min : left_min;
                }
                if (top->left)  stack.push_back(top->left);
                if (top->right) stack.push_back(top->right);
            } else {
                if (!top->left && !top->right) return k;
                if (top->left) 
                    left_min = closest_subtree_leaf(top->left, l_level);
                if (top->right) 
                    right_min = closest_subtree_leaf(top->right, r_level);
                return l_level <= r_level ? left_min : right_min;
            }
        }
        return 0;
    }

    int closest_subtree_leaf(TreeNode* root, int& level) {
        // 层序遍历
        level = 0;
        std::vector<TreeNode*> vec = {root};
        while (vec.empty() == false) {
            std::vector<TreeNode*> new_vec;
            new_vec.reserve(vec.size() << 1);
            for (auto node: vec) {
                if (node->left || node->right) {
                    if (node->left)  new_vec.emplace_back(node->left);
                    if (node->right) new_vec.emplace_back(node->right);
                } else return node->val;
            }
            if (new_vec.empty()) return vec[0]->val;
            level += 1;
            vec = std::move(new_vec);
        }
        return 0;
    }
};

int main(int argc, char** argv) {
    Solution sol;

    return 0;
}