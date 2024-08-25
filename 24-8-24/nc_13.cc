#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    int maxDepth(TreeNode* root) {
        // DFS 即可
        int max_depth = 0;
        if (root) max_depth_recursive(root, 1, max_depth);
        return max_depth;
    }

    void max_depth_recursive(TreeNode* root, int depth, int& max_depth) {
        max_depth = std::max(depth, max_depth);
        if (root->left)
            max_depth_recursive(root->left,  depth + 1, max_depth);
        if (root->right)
            max_depth_recursive(root->right, depth + 1, max_depth);
    }
};