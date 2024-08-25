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

/**
 * 思路比较混乱，但好在是知道怎么写
 * 具体思路：
 * (1) Hash: 给定一个前序遍历的 node，需要知道其中序遍历的位置
 * (2) 记录目前正在等待左右子树或右子树的节点，跳过所有不再可能有左子树的节点
 *      用一个 stack，保存了对应节点在中序遍历数组中的位置，以及对应 node
 *      逻辑是：当一个新元素在栈顶元素中序遍历数组的左侧时，则说明这就是栈顶元素的左孩子
 *             如果在右侧，则更复杂：
 *             - 弹栈，到：   (1) 遇到一个栈顶元素的位置在当前元素的右边，说明当前元素是弹栈之前元素的右孩子
 *                           (2) 栈空：说明当前元素是弹栈之前元素的右孩子
 *      找到对应的上一个元素后，入栈新元素即可。
 *      时间复杂度: O(n)，空间复杂度也是 O(n)
*/
class Solution {
public:
    /**
     * 重建二叉树：给定前序和中序遍历，求整个二叉树，返回头节点
     * 前序就是：根左右，中序就是：左根右
     * 我的思路是：中序遍历用于确定左右
     * 前序确定顺序，哈希
     */
    TreeNode* reConstructBinaryTree(std::vector<int>& preOrder, std::vector<int>& vinOrder) {
        int length = vinOrder.size();
        if (length == 0) return nullptr;
        std::unordered_map<int, int> pos_map;
        pos_map.reserve(length);
        for (int i = 0; i < length; i++) {
            int v = vinOrder[i];
            pos_map[v] = i;
        }
        auto head = new TreeNode(preOrder.front());
        std::vector<std::pair<int, TreeNode*>> stack;
        stack.reserve(8);
        stack.emplace_back(pos_map[head->val], head);
        for (int i = 1; i < length; i++) {
            int cur_v = preOrder[i];
            int cur_p = pos_map[cur_v];
            auto [top_p, top_node] = stack.back();
            if (cur_p < top_p) {
                // 如果 cur_p (当前节点中序遍历位置) 在栈顶元素的左边
                // 可以直接添加，栈顶是等待左右的节点，其他元素都是等待右的节点
                top_node->left = new TreeNode(cur_v);
                stack.emplace_back(cur_p, top_node->left);
            } else {
                // 如果是找右侧节点: 找到第一个 pos 小于 cur_pos 的元素
                // 还是需要从右边向左边找
                stack.pop_back();
                int old_p = top_p;
                auto old_n = top_node;

                while (!stack.empty()) {
                    auto [p, node] = stack.back();
                    if (cur_p < p) {
                        break;
                    }
                    stack.pop_back();
                    old_p = p;
                    old_n = node;
                }
                old_n->right = new TreeNode(cur_v);
                stack.emplace_back(cur_p, old_n->right);
            }
        }
        return head;
    }
};