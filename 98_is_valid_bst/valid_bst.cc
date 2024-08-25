#include "../ListNode.hpp"
/**
 * 这道题的思路并不难，恶心在我必须放大一轮整数范围（这让我呕吐）
 * runtime: 29.10%
 * memory:  97.92%
*/
constexpr long min_int = -2147483649;
constexpr long max_int = 2147483648;
class Solution {
public:
    bool isValidBST(TreeNode* root) {
        if (!root) return true;
        if (root->left) {
            int left_v = root->left->val;
            if (left_v >= root->val) return false;
            bool result = check_tree_recursive(root->left, min_int, root->val);
            if (!result) return false;
        }
        if (root->right) {
            int right_v = root->right->val;
            if (right_v <= root->val) return false;
            bool result = check_tree_recursive(root->right, root->val, max_int);
            if (!result) return false;
        }
        return true;
    }

    static bool check_tree_recursive(const TreeNode* const cur, long min_v, long max_v) noexcept {
        if (cur->left) {
            int left_v = cur->left->val;
            if (long(left_v) <= long(min_v) || left_v >= cur->val) return false;
            bool result = check_tree_recursive(cur->left, min_v, cur->val);
            if (!result) return false;
        }
        if (cur->right) {
            int right_v = cur->right->val;
            if (right_v <= cur->val || long(right_v) >= long(max_v)) return false;
            bool result = check_tree_recursive(cur->right, cur->val, max_v);
            if (!result) return false;
        }
        return true;
    }
};

int main() {
    Solution sol;

    return 0;
}