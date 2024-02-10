#include <iostream>
#include <vector>
#include <algorithm>
#include "../ListNode.hpp"

using namespace std;

/**
 * 
 * runtime: 100.00%
 * memory:  5.05%
 */
class Solution {
public:
    int sumNumbers(TreeNode* root) const {
        std::vector<int> dummy;
        return recursive_solve(root, dummy);
    }

    int recursive_solve(TreeNode* root, std::vector<int>& depths) const {
        int sum_res = 0;
        bool is_leaf = true;
        if (root->left) {
            is_leaf = false;
            std::vector<int> new_depths;
            sum_res += recursive_solve(root->left, new_depths);
            for (int& dep: new_depths) {
                dep *= 10;
                depths.push_back(dep);
                sum_res += root->val * dep;
            }
        }
        if (root->right) {
            is_leaf = false;
            std::vector<int> new_depths;
            sum_res += recursive_solve(root->right, new_depths);
            for (int& dep: new_depths) {
                dep *= 10;
                depths.push_back(dep);
                sum_res += root->val * dep;
            }
        }
        if (is_leaf) {
            sum_res += root->val;
            depths.push_back(1);
        }
        return sum_res;
    }
};

int main(int argc, char** argv) {
    Solution sol;

    return 0;
}