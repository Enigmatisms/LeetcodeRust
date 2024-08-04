#include <iostream>
#include <vector>
#include <deque>
#include "../ListNode.hpp"

using namespace std;

/**
 * 非常 straight forward
 * 判断某个 node 开始是否是相同的子树就行
 * runtime: 36.61%
 * memory:  14.25%
*/
class Solution {
public:
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        // 需要广度优先搜索
        std::deque<TreeNode*> bfs_q;
        bfs_q.emplace_back(root);
        int subroot_v = subRoot->val;
        while (bfs_q.empty() == false) {
            auto top = bfs_q.front();
            bfs_q.pop_front();
            if (top->val == subroot_v && isSameTree(top, subRoot)) return true;
            if (top->left) bfs_q.emplace_back(top->left);
            if (top->right) bfs_q.emplace_back(top->right);
        }
        return false;
    }

    // 如果 t1 != t2，我们将避免调用此函数。因为此函数为递归函数，是不能 inline 的
    bool isSameTree(TreeNode* t1, TreeNode* t2) const {
        if (t1->left && t2->left) {
            // 均存在，且值相同
            if (t1->left->val != t2->left->val) return false;
            if (!isSameTree(t1->left, t2->left)) return false;            
        } else if ((t1->left == nullptr) ^ (t2->left == nullptr)) {
            // 左子树存在性不相同
            return false;
        }
        if (t1->right && t2->right) {
            if (t1->right->val == t2->right->val) return false;
            if (!isSameTree(t1->right, t2->right)) return false;            
        } else if ((t1->right == nullptr) ^ (t2->right == nullptr)) {
            return false;
        }
        return true;        // 左右子树结构一致，且值相同，返回 true
    }
};

int main() {
  Solution sol;
  
  return 0; 
}