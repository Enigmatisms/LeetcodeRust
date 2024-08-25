#include <iostream>
#include <vector>
#include <algorithm>
#include "../ListNode.hpp"

using namespace std;

/**
 * 
 * runtime: 100.00%
 * memory:  27.63%
 */
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        if (!root) return {};
        std::vector<int> results;
        recursive_solve(results, root);
        return results;
    }

    void recursive_solve(std::vector<int>& result, TreeNode* current) const {
        result.push_back(current->val);
        if (current->left) recursive_solve(result, current->left);
        if (current->right) recursive_solve(result, current->right);
    }
};

int main(int argc, char** argv) {
    Solution sol;

    return 0;
}