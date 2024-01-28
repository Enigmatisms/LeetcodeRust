#include <iostream>
#include <vector>
#include "../ListNode.hpp"
using namespace std;

/**
 * easy piece of cake
 * runtime: 77.00%
 * memory:  93.09%
*/

class Solution {
public:
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        if (!root) return {};
        std::vector<std::vector<int>> results;
        std::vector<int> path;
        path_sum_recursive(results, path, root, targetSum);
        return results;
    }

    void path_sum_recursive(std::vector<std::vector<int>>& results, std::vector<int>& path, TreeNode* root, int target) {
        if (!root) return;
        int remaining = target - root->val;
        if (!root->left && !root->right) {      // leave node
            if (remaining == 0) {
                results.push_back(path);
                results.back().push_back(root->val);
            }
        } else {
            path.push_back(root->val);
            path_sum_recursive(results, path, root->left, remaining);
            path_sum_recursive(results, path, root->right, remaining);
            path.pop_back();
        }
    }
};

int main() {
  Solution sol;
  
  return 0; 
}