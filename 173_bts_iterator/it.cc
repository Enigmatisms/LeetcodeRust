#include <iostream>
#include <vector>
#include <algorithm>
#include "../ListNode.hpp"

using namespace std;

/**
 * 单调栈实现（确实有点意思） 
 * 看了题解才知道的另一种方法
 * 很容易理解，快速看完题解就能用它的方法秒杀
 * run: 64.55%
 * mem: 61.59%
 */
class BSTIterator {
private:
    std::vector<TreeNode*> node_stack;
public:
    BSTIterator(TreeNode* root) {
        while (root) {
            node_stack.emplace_back(root);
            root = root->left;
        }
    }
    
    int next() {
        auto node = node_stack.back();
        int res = node->val;
        node_stack.pop_back();
        if (node->right) {
            node = node->right;
            while (node) {
                node_stack.emplace_back(node);
                node = node->left;
            }
        }
        return res;
    }
    
    bool hasNext() const {
        return !node_stack.empty();
    }
};

/**
 * 暴力法: 保存中序遍历值，但这确实不是迭代器该有的设计，只是能把题做出来
 * runtime: 82.60%
 * memory:  36.27%
 */
class BSTIterator {
private:
    std::vector<int> in_order;
    int next_ptr = -1;

    void recursive_traverse(TreeNode* node) {
        if (node->left)
            recursive_traverse(node->left);
        in_order.emplace_back(node->val);
        if (node->right)
            recursive_traverse(node->right);
    }
public:
    BSTIterator(TreeNode* root) {
        in_order.reserve(32);
        recursive_traverse(root);
    }
    
    int next() {
        return in_order[++next_ptr];
    }
    
    bool hasNext() {
        return next_ptr + 1 < in_order.size();
    }
};

int main(int argc, char** argv) {

    return 0;
}