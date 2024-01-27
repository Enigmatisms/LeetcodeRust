#include <iostream>
#include <vector>
#include "../ListNode.hpp"
using namespace std;

/**
 * runtime: 98.52%
 * memory:  5.01% (stable but sucks)
*/

class Solution {
public:
    bool isBalanced(TreeNode* root) const {
        int dummy = 0;
        return is_balanced_recursive(root, dummy);
    }

    bool is_balanced_recursive(TreeNode* root, int& depth) const {
        if (!root) {
            depth = 0;
            return true;
        }
        int dl = 0, dr = 0;
        bool balanced_left  = is_balanced_recursive(root->left, dl);
        bool balanced_right = is_balanced_recursive(root->right, dr);
        if (balanced_left && balanced_right) {
            if (abs(dl - dr) <= 1) {
                depth = std::max(dl, dr) + 1;
                return true;
            }
        }
        return false;
    }
};

int main() {
  Solution sol;
  
  return 0; 
}