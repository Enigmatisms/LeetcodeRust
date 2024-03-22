#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <unordered_map>
#include <unordered_set>
#include "../ListNode.hpp"

using namespace std;

/**
 * runtime: 74.42%
 * memory:  58.14%
 */
class Solution {
public:
    int minimumOperations(TreeNode* root) {
        std::vector<TreeNode*> stack = {root};
        int min_op_cnt = 0;
        while (stack.empty() == false) {
            std::vector<TreeNode*> new_stack;
            new_stack.reserve(stack.size() << 1);
            for (auto node: stack) {
                if (node->left)  new_stack.push_back(node->left);
                if (node->right) new_stack.push_back(node->right);
            }
            if (stack.size() > 1) {
                std::vector<int> original(stack.size()), sorted;
                for (size_t i = 0; i < stack.size(); i++)
                    original[i] = stack[i]->val;
                sorted = original;
                std::sort(sorted.begin(), sorted.end());
                std::unordered_map<int, int> pos_mapping;
                pos_mapping.reserve(stack.size());
                for (size_t i = 0; i < original.size(); i++)
                    pos_mapping[original[i]] = i;
                for (size_t i = 0; i < original.size(); i++) {
                    int &o_num = original[i], s_num = sorted[i];
                    if (o_num == s_num) continue;
                    int &s_pos = pos_mapping[s_num];
                    // 这是会有问题的，为什么？
                    std::swap(o_num, original[s_pos]);
                    std::swap(s_pos, pos_mapping[o_num]);
                    min_op_cnt ++;
                }
            }
            stack = std::move(new_stack);
        }
        return min_op_cnt;
    }
};

int main(int argc, char** argv) {
    Solution sol;

    return 0;
}