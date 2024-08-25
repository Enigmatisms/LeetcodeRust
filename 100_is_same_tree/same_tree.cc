#include "../ListNode.hpp"
#include <vector>

/**
 * 不愧是简单题
 * runtime: 100%
 * memory:  62.56%
*/
class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) const noexcept {
        if (!p && !q) {
            return true;
        }
        if (!p || !q) {
            return false;
        }
        std::vector<TreeNode*> stack1{p}, stack2{q};
        while (stack1.empty() == false) {
            auto t1 = stack1.back(), t2 = stack2.back();
            stack1.pop_back();
            stack2.pop_back();
            if (t1->val != t2->val) return false;
            bool t1_l = t1->left != nullptr, t1_r = t1->right != nullptr;
            if ((t1_l ^ (t2->left != nullptr)) || (t1_r ^ (t2->right != nullptr))) return false;
            if (t1_l) {
                stack1.push_back(t1->left);
                stack2.push_back(t2->left);
            }
            if (t1_r) {
                stack1.push_back(t1->right);
                stack2.push_back(t2->right);
            }
        }
        return true;
    }
};