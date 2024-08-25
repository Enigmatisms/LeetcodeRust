#include <iostream>
#include <vector>
#include <algorithm>
#include "../ListNode.hpp"

using namespace std;

/**
 * 先根据层序遍历恢复并且还原
 * runtime:  95.36%
 * memory:   64.24%
 */
class FindElements {
private:
    TreeNode* rnode;
public:
    FindElements(TreeNode* root) {
        rnode = root;
        recurse_recover(root, 0);
    }
    
    bool find(int target) {
        // break down the target value
        std::vector<int> components;
        while (target) {
            components.push_back(target);
            if (target & 1) {
                target = (target - 1) >> 1;
            } else {
                target = (target - 2) >> 1;
            }
        }
        TreeNode* ptr = rnode;
        while (ptr && components.empty() == false) {
            int top = components.back();
            components.pop_back();
            if (top & 1) {
                ptr = ptr->left;
            } else {
                ptr = ptr->right;
            }
        }
        if (!ptr) return false;
        return true;
    }

    void recurse_recover(TreeNode* cur_node, int val) {
        cur_node->val = val;
        val <<= 1;
        if (cur_node->left)
            recurse_recover(cur_node->left, val + 1);
        if (cur_node->right)
            recurse_recover(cur_node->right, val + 2);
    }
};


int main(int argc, char** argv) {
    return 0;
}