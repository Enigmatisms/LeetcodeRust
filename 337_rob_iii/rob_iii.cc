#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <unordered_map>
#include <unordered_set>
#include "../ListNode.hpp"

using namespace std;

/**
 * 这道题很有趣
 * 
 * 打家劫舍二叉树版... 评价是小偷也得懂算法
 * 递归版，但是不能真去递归，会出现组合爆炸问题
 * 树上DP... 第一次见呢
 * 树上 DP 一般需要递归（因为很难存在一个线性表里，线性化需要前中后或者层序遍历，会导致分不清楚某个节点与另一个节点的关系）
 * 
 * 本题思路: 用后序遍历。我们先确定了孩子的情况（如果是递归，实际上是所有孩子的情况），再确定父的情况
 * 那么孩子的情况实际有两种：偷当前节点，以及不偷当前节点。那么每次我们回传给父的，都是当前孩子节点偷与不偷得到的最大值
 * 
 * (1) 确定 DP 数组含义
 * dp[0] 表示本孩子没被偷，并完成其所有子节点的偷窃，能得到的最大金额
 * dp[1] 表示本孩子被偷，并完成其所有子节点的偷窃，能得到的最大金额
 * 
 * (2) 递推
 * 注意，本问题是递归的树上，所以会有
 * 
 * left_dp[0]/[1], 与 right_dp[0]/[1]。
 * 那么如果我们决定偷父，那
 * father[1] = father->gold + left_dp[0] + right_dp[0];
 * 如果我们决定不偷父，那么
 * father[0] = max(left_dp[0], left_dp[1]) + max(right_dp[0], right_dp[1]);
 * 
 * 所以，这样递归就完成了
 * (3) 初始化
 * 对于叶子节点，显然有 dp[0] = 0, dp[1] = val
 * 但这样不太方便写，每次要去判定一个 node->left 是否为 nullptr，如果是 还得单独把对应 left_dp / right_dp 初始化出来
 * 我们直接设定初始化为: nullptr 返回 {0, 0}
 * 
 * (4) 空间复杂度优化
 * 不太好优化
 * 
 * runtime: 86.11%
 * memory:  97.54%
 */
class Solution {
public:
    int rob(TreeNode* root) {
        auto [root_0, root_1] = recursive_rob(root);
        return std::max(root_0, root_1);
    }

    std::pair<int, int> recursive_rob(TreeNode* node) {
        if (!node) return {0, 0};
        auto [lchild_0, lchild_1] = recursive_rob(node->left);
        auto [rchild_0, rchild_1] = recursive_rob(node->right);

        int father_0 = std::max(lchild_0, lchild_1) + std::max(rchild_0, rchild_1),
            father_1 = node->val + lchild_0 + rchild_0;
        return {father_0, father_1};
    }
};

int main(int argc, char** argv) {
    Solution sol;

    return 0;
}