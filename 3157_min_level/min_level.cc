#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include "../ListNode.hpp"

using namespace std;

/**
 * 很简单的一道题，3min 内 AC
 * runtime: 50.00%
 * memory:  21.43%
 */
class Solution {
public:
    int minimumLevel(TreeNode* root) {
        std::vector<TreeNode*> level = {root};
        long long min_val = root->val;
        int min_level = 1;
        for (int cur_level = 1; !level.empty(); cur_level ++) {
            std::vector<TreeNode*> new_level;
            new_level.reserve(level.size() << 1);
            long long local = 0;
            for (auto& node: level) {
                local += static_cast<long long>(node->val);
                if (node->left) new_level.push_back(node->left);
                if (node->right) new_level.push_back(node->right);
            }
            if (local < min_val) {
                min_level = cur_level;
                min_val   = local;
            }
            level = std::move(new_level);
        }
        return min_level;
    }
};

int main(int argc, char** argv) {
    Solution sol;

    return 0;
}