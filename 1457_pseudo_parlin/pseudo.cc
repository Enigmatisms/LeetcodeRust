#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <unordered_map>
#include <unordered_set>
#include "../ListNode.hpp"

using namespace std;

/**
 * 这道题太简单了... 秒杀水平
 * runtime: 94.85%
 * memory:  96.20%
 */
class Solution {
private:
    std::array<int, 10> digit_cnt;
public:
    int pseudoPalindromicPaths (TreeNode* root) {
        recursive_dfs(root);
        return digit_cnt[0];
    }

    void recursive_dfs(TreeNode* cur_node) {
        digit_cnt[cur_node->val] ++;
        if (cur_node->left || cur_node->right) {
            if (cur_node->left)  recursive_dfs(cur_node->left);
            if (cur_node->right) recursive_dfs(cur_node->right);
        } else {        // leaf node
            int odd_cnt = 0;
            for (int i = 1; i < 10; i++) {
                odd_cnt += digit_cnt[i] & 1;
                if (odd_cnt > 1) break;
            }
            digit_cnt[0] += odd_cnt <= 1;
        }
        digit_cnt[cur_node->val] --;
    }
};

int main(int argc, char** argv) {
    Solution sol;

    return 0;
}