#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include "../ListNode.hpp"

using namespace std;

/**
 * 思路不难: (1) 层序遍历可以 encode 从上到下的信息, 故需要 BFS (2) 记录col_id (可以用线性表)
 * (3) 记录每个表项（vector）的 size 变化，如果大于 1，则需要 sort
 * runtime: 100.00%
 * memory:  98.87%
 */
class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        std::vector<std::vector<int>> non_negs, negs;
        std::vector<std::pair<int, TreeNode*>> bfs_queue;      // level order traversal
        bfs_queue.emplace_back(0, std::move(root));
        while (bfs_queue.empty() == false) {
            std::vector<std::pair<int, TreeNode*>> new_queue;

            std::vector<size_t> non_neg_size(non_negs.size()), neg_size(negs.size());
            for (size_t i = 0; i < non_negs.size(); i++)
                non_neg_size[i] = non_negs[i].size();
            for (size_t i = 0; i < negs.size(); i++)
                neg_size[i] = negs[i].size();

            new_queue.reserve(bfs_queue.size() << 1);
            for (auto [col_id, node]: bfs_queue) {
                if (col_id >= 0) {
                    if (col_id >= non_negs.size())
                        non_negs.emplace_back();
                    non_negs[col_id].push_back(node->val);
                } else {
                    if (-col_id > negs.size())
                        negs.emplace_back();
                    int index = -col_id - 1;
                    negs[index].push_back(node->val);
                }
                if (node->left)  new_queue.emplace_back(col_id - 1, node->left);
                if (node->right) new_queue.emplace_back(col_id + 1, node->right);
            }
            for (size_t i = 0; i < non_negs.size(); i++) {
                size_t old_size = 0;
                if (i < non_neg_size.size()) old_size = non_neg_size[i];
                if (non_negs[i].size() - old_size <= 1) continue;
                std::sort(non_negs[i].begin() + old_size, non_negs[i].end());
            }
            for (size_t i = 0; i < negs.size(); i++) {
                size_t old_size = 0;
                if (i < neg_size.size()) old_size = neg_size[i];
                if (negs[i].size() - old_size <= 1) continue;
                std::sort(negs[i].begin() + old_size, negs[i].end());
            }
            bfs_queue = std::move(new_queue);
        }
        std::reverse(negs.begin(), negs.end());
        negs.insert(negs.end(), non_negs.begin(), non_negs.end());
        return negs;
    }
};

int main(int argc, char** argv) {
    Solution sol;

    return 0;
}