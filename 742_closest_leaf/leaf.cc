#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <unordered_map>
#include <unordered_set>
#include "../ListNode.hpp"

using namespace std;

/**
 * 先求出所有子树的最近结点，之后回溯
 * runtime: 53.33%
 * memory:  26.67%
 */
class Solution {
using Pair = std::pair<int, int>;
public:
    Pair closest_leaf(TreeNode* root, std::unordered_map<int, Pair>& map, std::unordered_map<int, int>& father) {
        Pair pl(0, 1001), pr(0, 1001);
        if (root->left) {
            pl = closest_leaf(root->left, map, father);
            father[root->left->val] = root->val;
        }
        if (root->right) {
            pr = closest_leaf(root->right, map, father);
            father[root->right->val] = root->val;
        }
        if (pl.first || pr.first) {
            Pair p_root = pl.second <= pr.second ? pl : pr;
            ++ p_root.second;
            map[root->val] = p_root;
            return p_root;
        }
        map[root->val] = Pair(root->val, 0);
        return Pair(root->val, 0);
    }

    int findClosestLeaf(TreeNode* root, int k) {
        std::unordered_map<int, Pair> map;
        std::unordered_map<int, int> father;
        father.emplace(root->val, 0);
        closest_leaf(root, map, father);                // map stores all the closest node in a sub-tree
        auto it = map.find(k);
        int min_node = it->second.first, min_val = it->second.second;
        if (min_val == 0) return k;
        int ptr = father[k];
        for (int i = 1; ptr > 0; i++, ptr = father[ptr]) {
            auto cit = map.find(k);
            int node = cit->second.first, val = cit->second.second;
            if (val + i < min_val) {
                min_val  = val + i;
                min_node = node;
            }
        }
        return min_node;
    }
};

int main(int argc, char** argv) {
    Solution sol;

    return 0;
}