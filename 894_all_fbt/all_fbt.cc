#include <iostream>
#include <vector>
#include <algorithm>
#include "../ListNode.hpp"

using namespace std;

/**
 * 这道题很简单啊，不用递归完全能做
 * 非常舒服 秒杀 感觉不是中等题
 * runtime: 98.75%
 * memory:  91.25%
 */
class Solution {
public:
    vector<TreeNode*> allPossibleFBT(int n) {
        if ((n & 1) == 0) return {};        // 偶数无法形成真 FBT
        // 递归的复杂度以及内存开销会大一些，我们用正向算就行
        std::vector<std::vector<TreeNode*>> possibles = {
            {new TreeNode(0)},
        };
        for (int i = 3; i <= n; i += 2) {
            possibles.emplace_back();
            auto& back = possibles.back();
            for (int j = 1; j < i; j += 2) {
                int lidx = j >> 1, ridx = (i - 1 - j) >> 1;
                for (TreeNode* lchild: possibles[lidx]) {
                    for (TreeNode* rchild: possibles[ridx]) {
                        TreeNode* head = new TreeNode(0, lchild, rchild);
                        back.emplace_back(std::move(head));
                    }
                }
            }
        }
        return possibles.back();
    }
};

int main(int argc, char** argv) {
    Solution sol;

    return 0;
}