#include <iostream>
#include <vector>
#include <algorithm>
#include "../ListNode.hpp"

using namespace std;

/**
 * 很简单的一道题，但是很容易写错
 * 比如忘记重启，或者用了 if else 而不是双 if（一遍 fail 另一边还可以）
 * 注意，这是 DFS，搜索一定要“全面”
 * runtime: 64.43%
 * memory:  32.83%
 */
class Solution {
public:
    int longestZigZag(TreeNode* root) {
        uint16_t max_zigzag = 0;
        if (root->left)
            recursiveLong<true>(root->left, 0, max_zigzag);
        if (root->right)
            recursiveLong<false>(root->right, 0, max_zigzag);
        return (int)max_zigzag;
    }

    template <bool last_left>
    void recursiveLong(TreeNode* root, uint16_t zigzag, uint16_t& max_zigzag) {
        // zigzag 最高位为 1，如果上次是从父向左到子
        zigzag += 1;
        max_zigzag = std::max(zigzag, max_zigzag);
        if constexpr (last_left) {      // 父节点左，所以本次右
            if (root->right)
                recursiveLong<false>(root->right, zigzag, max_zigzag);
            if (root->left)          // 本次应该向右，但右没有了，只能重启左
                recursiveLong<true>(root->left, 0, max_zigzag);
        } else {
            if (root->left)
                recursiveLong<true>(root->left, zigzag, max_zigzag);
            if (root->right)         // 本次应该向左，但是左无了，只能重启右
                recursiveLong<false>(root->right, 0, max_zigzag);
        }
    }
};

int main(int argc, char** argv) {
    Solution sol;

    return 0;
}