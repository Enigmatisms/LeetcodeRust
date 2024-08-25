#include <iostream>
#include <vector>
#include <algorithm>
#include "../ListNode.hpp"

using namespace std;

/**
 * runtime: 84.98%
 * memory:  27.17%
 */
class Solution {
public:
    // 更简单的版本
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) const {
        if (!root || root == p || root == q) return root;
        auto lptr = lowestCommonAncestor(root->left,  p, q);
        auto rptr = lowestCommonAncestor(root->right, p, q);
        if (lptr && rptr)       // 说明左边找到了，右边也找到了，这只有一种情况: p q 分别在 root 的左右子树
            return root;
        else if (lptr)          // 右边没找到(如果反上去一直没找到 rptr，说明在本 lptr 下面)
            return lptr;
        /**
         * 逻辑妙处：如果不是两个都找到了（两个都找到是最好理解的），以 lptr 找到为例
         * 要么就是，可能LCA 还在上层一些，等之后的 rptr 看是否能返回找到
         * 如果 rptr 在上层找到了，说明 LCA 在更靠近根的地方。如果一直没找到，说明 lptr 下面同时存在两个
         * 那么就是最先找到其中一个的那个节点（最开始返回 lptr）是 LCA
         * 
         * 如果lptr,rptr都找到，那么就说明p，q左右各一个
         * 只要找到LCA（出现了lptr,rptr同时 true 的情况），往上走的 lptr,rptr必定只有一个是非空的了
         * 这样就保证了 LCA的传递
         */
        return rptr;            // 不管 rptr 是不是 null，都得返回 rptr 了
    }
};


/**
 * 看看能不能把 LCA 写清楚
 * 清楚是清楚了，就是复杂
 * 基本想法是：DFS，找到第一个以后：
 * （1）先 DFS 自己，找到了第二个就返回自己
 * （2）对 DFS 记录的祖先节点们，从深到浅 DFS，注意 DFS 时避开原来的子树（即向另一个子树走）
 * 
 * 一遍过了，但是很慢，但是理解起来不成问题（可能这就是我的风格吧... 容易写出复杂代码来，是一种垃圾的体现）
 * runtime: 7.79% (很慢)
 * memory:  14.32%
 */
class Solution2 {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        // 外层 DFS 时需要记录父节点，以及父探查的是左子树还是右子树
        std::vector<std::pair<bool, TreeNode*>> ancs;
        ancs.reserve(8);
        return dfs_record(ancs, root, p->val, q->val);
    }

    TreeNode* dfs_record(std::vector<std::pair<bool, TreeNode*>>& ancs, TreeNode* node, int v1, int v2) {
        if (node->val == v1 || node->val == v2) {
            int to_find = node->val == v1 ? v2 : v1;
            if (node->left && dfs_find_one(node->left, to_find))
                return node;
            if (node->right && dfs_find_one(node->right, to_find))
                return node;
            while (!ancs.empty()) {
                auto [is_lchild, father] = ancs.back();
                ancs.pop_back();
                if (is_lchild && father->right && dfs_find_one(father->right, to_find))
                    return father;
                else if (!is_lchild && father->left && dfs_find_one(father->left, to_find))
                    return father;
            }
        } else {
            if (node->left) {
                ancs.emplace_back(true, node);
                auto n = dfs_record(ancs, node->left, v1, v2);
                if (n != nullptr) return n;
                ancs.pop_back();
            }
            if (node->right) {
                ancs.emplace_back(false, node);
                auto n = dfs_record(ancs, node->right, v1, v2);
                if (n != nullptr) return n;
                ancs.pop_back();
            }
        }
        return nullptr;
    }

    bool dfs_find_one(TreeNode* root, int val) {
        std::vector<TreeNode*> stack;
        stack.reserve(8);
        stack.emplace_back(root);
        while (!stack.empty()) {
            auto top = stack.back();
            stack.pop_back();
            if (top->val == val) return true;
            if (top->left)
                stack.push_back(top->left);
            if (top->right)
                stack.push_back(top->right);
        }
        return false;
    }
};

int main(int argc, char** argv) {
    Solution sol;

    return 0;
}