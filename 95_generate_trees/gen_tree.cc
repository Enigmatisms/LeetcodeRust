#include "../ListNode.hpp"
/**
 * 概念不清（不学当然不知道什么叫二叉搜索树，以为是普通树呢），
 * 我这不是二叉搜索树，是各种可能的二叉树结构，正确应该是正确的，但内部的值不符合要求
 * runtime: 90.23%
 * memory:  87.80%
 */
class Solution {
public:
    std::vector<TreeNode*> generateTrees(int n) const {
        return gen_bst_recursive(1, n);
    }

    // 这简单多了，不过注意，二叉搜索树一定满足中序遍历情况下的有序性（无论是升还是降）
    std::vector<TreeNode*> gen_bst_recursive(int start, int end) const {
        // 如果这样的话，应该是对根可能的情况进行遍历递归
        if (start > end) return {nullptr};
        else if (start == end) return {new TreeNode(start)};
        std::vector<TreeNode*> results;
        for (int root = start; root <= end; root++) {        // set current as root
            auto left_cases  = gen_bst_recursive(start, root - 1);
            auto right_cases = gen_bst_recursive(root + 1, end);
            for (TreeNode* left: left_cases) {
                for (TreeNode* right: right_cases) {
                    results.push_back(new TreeNode(root, left, right));
                }
            } 
        }
        return results;
    }

    // 以下非题目所要求实现
    std::vector<TreeNode*> generateTreeStructures(int n) const {
        return gen_tree_struct_recursive(1, n);
    }

    std::vector<TreeNode*> gen_tree_struct_recursive(int start, int num) const {
        if (num == 0) return {nullptr};
        else if (num == 1) return {new TreeNode(start)};
        std::vector<TreeNode*> results;
        for (int i = 0; i < num; i++) {
            auto left_cases  = gen_tree_struct_recursive(start + 1, num - 1 - i);
            auto right_cases = gen_tree_struct_recursive(start + num - i, i);
            for (TreeNode* left: left_cases) {
                for (TreeNode* right: right_cases) {
                    results.push_back(new TreeNode(start, left, right));
                }
            } 
        }
        return results;
    }
};

int main(int argc, char** argv) {    
    Solution sol;
    int value = argc > 1 ? atoi(argv[1]) : 3;
    auto results = sol.generateTrees(value);
    for (auto node: results) {
        auto vals = node->inorderTraversal();
        for (int v: vals)
            printf("%d -> ", v);
        printf("\n");
    }
    printf("%lu solutions in total.\n", results.size());
    return 0;
}