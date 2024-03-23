#include <iostream>
#include <vector>
#include <algorithm>
#include "../ListNode.hpp"

using namespace std;

/**
 * 随便试了试不使用递归，递归太垃圾了
 * runtime: 71.42%
 * memory:  80.70%
 */
class Solution {
using Pair = std::pair<TreeNode*, bool>;
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        std::vector<Pair> stack;
        stack.emplace_back(root, false);
        std::vector<string> results, result;
        while (stack.empty() == false) {
            auto& pr = stack.back();
            if (pr.second == true) {
                result.pop_back();
                stack.pop_back();
            } else {
                pr.second = true;
                result.push_back(std::to_string(pr.first->val));
                if (pr.first->left || pr.first->right) {        // non-leaf
                    auto ptr = pr.first;
                    if (ptr->right) stack.emplace_back(ptr->right, false);
                    if (ptr->left)  stack.emplace_back(ptr->left,  false);
                } else {            // leaf
                    // push one to results
                    std::string res = result[0];
                    for (auto it = result.cbegin() + 1; it != result.cend(); it++) {
                        res.append("->");
                        res.append(*it);
                    }
                    results.push_back(res);
                    result.pop_back();
                    stack.pop_back();
                }
            }
        }
        return results;
    }
};

int main(int argc, char** argv) {
    Solution sol;

    return 0;
}