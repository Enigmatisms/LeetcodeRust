#include <iostream>
#include <vector>
#include <algorithm>
#include "../ListNode.hpp"

using namespace std;

/**
 * 删除二叉搜索树，最关键的一点就是:被函数的节点，要么是其左子树的最右边（一步都不能往左走）上，要么是右子树的最左边上
 * 如果左子树完全没有右子树，可以直接上，最简单
 * 同理右子树也是
 * runtime: 85.28%
 * memory:  8.05%
 */
class Solution {
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        TreeNode dirt, *parent = &dirt, *ptr = nullptr;
        dirt.left = root;
        bool found = false, is_rchild = false;
        while (root) {
            if (root->val == key) {
                found = true;
                break;
            }
            parent = root;
            is_rchild = root->val < key;
            root = is_rchild ? root->right : root->left;
        }
        if (found == false) return dirt.left;
        found = root == dirt.left;      // found 的意义变为：如果 found 为 true 则说明删掉的是根节点
        if (root->left) {
            if (root->left->right == nullptr) {
                ptr = root->left;
                ptr->right = root->right;
            } else {
                TreeNode* fa = root->left;
                ptr = fa->right;
                while (ptr->right) {
                    fa = ptr;
                    ptr = ptr->right;
                }
                fa->right = ptr->left;
                ptr->left = root->left;         // ptr->left 已经接在 fa 的右子树上，所以作为替换，需要更新左子树为被删掉的节点的左
                ptr->right = root->right;       // 右也更新
            }
        } else if (root->right) {
            if (root->right->left == nullptr) {
                ptr = root->right;
                ptr->left = root->left;
            } else {                        // 继续查
                TreeNode* fa = root->right;
                ptr = fa->left;
                while (ptr->left) {
                    fa = ptr;
                    ptr = ptr->left;
                }
                fa->left = ptr->right;
                ptr->left = root->left; 
                ptr->right = root->right;
            }
        } else {
            ptr = nullptr;
        }
        if (is_rchild)
            parent->right = ptr;
        else
            parent->left = ptr;
        return dirt.left;
    }
};

int main(int argc, char** argv) {
    Solution sol;

    return 0;
}