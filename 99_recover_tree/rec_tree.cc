#include "../ListNode.hpp"

/**
 * 这道题我的 memory 使用是 O(1)。内存开销从实现上来说还可以更小，显然: 我们只需要把 TreeNode** 换成 int** 即可
 * 此题的思想是用中序遍历判定树结构出现了什么问题: 中序遍历中，如果出现了后来的值小于前序值，则说明对应前序值是需要替换的值之一
 * 我们找到比前序值还大的值之后，对应值的前一个值是需要替换的值
 * 这题我提交老错，是因为我在右子树的判定中也会考虑增加 error_node:
 * 
 * ```
 * if (root->right) {
            bool ret = dfs_tree(root->right, prev_node, err_node);
            if (ret) return true;
        }

        if (*err_node) {
            if (cur_val > (*err_node)->val) {
                std::swap((*prev_node)->val, (*err_node)->val);
                return true;
            }
        } else if ((*prev_node)->val > cur_val) {       // 从这一句开始是错的
            *err_node = *prev_node;
        }
    ```
    为什么错？很简单: prev_node 将会是右子树上的某个值（对应值就是应该比cur_val大）
    所以右子树遍历之后，由于 prev_node 被更新了，此时不进行判定
    太久没做题了都傻了
 * 
 * runtime: 99.31%
 * memory:  76.34%
 * 
*/
class Solution {
public:
    // DFS 即可
    void recoverTree(TreeNode* root) const noexcept {
        TreeNode **prev_node = new TreeNode*, **err_node = new TreeNode*;
        int prev_v = 0, err_v = 0;
        *prev_node = nullptr;
        *err_node  = nullptr;
        bool ret = dfs_tree(root, prev_node, err_node);
        if (!ret) { // the last node should be swapped
            std::swap((*prev_node)->val, (*err_node)->val);
        }
        delete prev_node;
        delete err_node;
    }

    bool dfs_tree(TreeNode* root, TreeNode** prev_node, TreeNode** err_node) const noexcept {
        int cur_val = root->val;
        if (root->left) {
            bool ret = dfs_tree(root->left, prev_node, err_node);
            if (ret) return true;
        }
        if (*prev_node) {
            if (*err_node) {
                if (cur_val > (*err_node)->val) {
                    std::swap((*prev_node)->val, (*err_node)->val);
                    return true;
                }
            } else if ((*prev_node)->val > cur_val) {
                *err_node = *prev_node;
            }
        }
        *prev_node = root;
        if (root->right) {
            bool ret = dfs_tree(root->right, prev_node, err_node);
            if (ret) return true;
        }

        if (*err_node) {
            if (cur_val > (*err_node)->val) {
                std::swap((*prev_node)->val, (*err_node)->val);
                return true;
            }
        }
        return false;
    }
};

int main() {
    Solution sol;
    std::vector<TreeNode> nodes(4);
    nodes[0] = TreeNode(2, nullptr, nullptr);
    nodes[1] = TreeNode(1, nullptr, &nodes[0]);
    nodes[2] = TreeNode(4, &nodes[1], nullptr);
    nodes[3] = TreeNode(3, &nodes[2], nullptr);

    sol.recoverTree(&nodes[3]);
    return 0;
}