#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <unordered_map>
#include <unordered_set>
#include "../ListNode.hpp"

using namespace std;

/**
 * 考 辛 斯！ 这道题一眼 BFS, 只能说秒杀
 * runtime: 75.63%
 * memory:  18.13%
 */
class Solution {
public:
    TreeNode* replaceValueInTree(TreeNode* root) {
        std::vector<std::pair<TreeNode*, int>> bfs_queue;
        bfs_queue.emplace_back(root, 0);
        while (bfs_queue.empty() == false) {
            std::vector<std::pair<TreeNode*, int>> new_queue;
            new_queue.reserve(bfs_queue.size() << 1);
            if (bfs_queue.size() > 1) {
                int all_sum = 0, queue_size = bfs_queue.size();
                for (int i = 0; i < queue_size; i++) {
                    const auto& node = bfs_queue[i].first;
                    all_sum += node->val;
                    if (node->left)  new_queue.emplace_back(node->left,  i);
                    if (node->right) new_queue.emplace_back(node->right, i);
                }
                for (int i = 0; i < queue_size; i++) {
                    auto& [node, father] = bfs_queue[i];
                    node->val = all_sum - node->val;
                    if (i + 1 < queue_size && bfs_queue[i + 1].second == father) {
                        i++;
                        auto& [brother, _] = bfs_queue[i];
                        node->val -= brother->val;
                        brother->val = node->val;
                    }
                }
            } else {
                auto& node = bfs_queue[0].first;
                node->val  = 0;
                if (node->left)  new_queue.emplace_back(node->left,  0);
                if (node->right) new_queue.emplace_back(node->right, 0);
            }
            bfs_queue = std::move(new_queue);
        }
        return root;
    }
};

int main(int argc, char** argv) {
    Solution sol;

    return 0;
}