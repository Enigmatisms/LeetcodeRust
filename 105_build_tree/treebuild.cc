#include <vector>
#include <iostream>
#include <unordered_set>
#include <unordered_map>
#include "../ListNode.hpp"

/**
 * 干，我说怎么想得这么慢，我理解成了层序遍历与中序遍历
 * 
*/

class Solution {
    std::unordered_map<int, int> mapping;
public:
    TreeNode* buildTree(const std::vector<int>& preorder, const std::vector<int>& inorder) const {
        // 这道题不用再写第二遍了，因为就是很简单... 直接写下一题
    }

    TreeNode* tree_build_recursive(
        const std::vector<int>& preorder, const std::vector<int>& inorder, int root_idx
    ) {
        int root_v = preorder[root_idx], inorder_idx = (*mapping.find(root_v)).second;
        TreeNode* new_node = new TreeNode(root_v, nullptr, nullptr);
        
    }

    /**
     * 下面是更加暴力的方法: woc 误打误撞
     * runtime: 5.22%
     * memory:  5.02%
    */
    TreeNode* buildTree2(const std::vector<int>& preorder, const std::vector<int>& inorder) const {
        if (preorder.size() <= 1)
            return preorder.empty() ? nullptr : new TreeNode(preorder.front(), nullptr, nullptr);
        short front_val = preorder.front();
        for (short j = 0; j < inorder.size(); j++) {
            if (inorder[j] != front_val) continue;
            std::vector<short> linorder(inorder.begin(), inorder.begin() + j), rinorder(inorder.begin() + j + 1, inorder.end());
            std::unordered_set<short> left_set(linorder.begin(), linorder.end()), right_set(rinorder.begin(), rinorder.end());
            std::vector<bool> used(preorder.size(), false);
            used[0] = true;
            auto lnode = tree_build_recursive2(preorder, used, std::move(linorder), std::move(left_set));
            auto rnode = tree_build_recursive2(preorder, used, std::move(rinorder), std::move(right_set));
            return new TreeNode(front_val, lnode, rnode);
        }
        return nullptr;
    }

    TreeNode* tree_build_recursive2(
        const std::vector<int>& preorder, std::vector<bool>& used,
        std::vector<short>&& inorder, std::unordered_set<short>&& bucket
    ) const {
        if (inorder.empty()) return nullptr;
        for (short i = 0; i < preorder.size(); i++) {
            if (used[i] == true) continue;
            short val = static_cast<short>(preorder[i]);
            auto it = bucket.find(val);
            if (it == bucket.end()) continue;
            used[i] = true;
            for (short j = 0; j < inorder.size(); j++) {
                if (inorder[j] != val) continue;
                std::vector<short> linorder(inorder.begin(), inorder.begin() + j), rinorder(inorder.begin() + j + 1, inorder.end());
                std::unordered_set<short> left_set(linorder.begin(), linorder.end()), right_set(rinorder.begin(), rinorder.end());
                auto lnode = tree_build_recursive2(preorder, used, std::move(linorder), std::move(left_set));
                auto rnode = tree_build_recursive2(preorder, used, std::move(rinorder), std::move(right_set));
                return new TreeNode(val, lnode, rnode);
            }
        }
        return nullptr;
    }
};

int main(int argc, char** argv) {
    Solution sol;

    return 0;
}