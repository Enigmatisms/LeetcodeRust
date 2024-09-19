#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/**
 * 这道题的思路很简单，n 个柱子，选择其中哪一个为高时
 * 最大的面积，是其能向两边延展的距离
 * 暴力去做：O(n^2)
 * 快速的方法是单调栈，用两个方向的单调栈可以求出向左和向右能延申的距离
 * 单调栈问题：首先需要确定是递增栈还是递减栈
 * runtime: 89.66%
 * memory:  8.57%
 */
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int length = heights.size();
        // 单调栈是递增栈
        std::vector<std::pair<int, int>> stack;
        std::vector<int> rightward(length), leftward(length);
        stack.reserve(length);
        // 向右
        stack.emplace_back(0, heights[0]);
        for (int i = 1; i < length; i++) {
            int cur_v = heights[i];
            while (!stack.empty()) {
                const auto [idx, val] = stack.back();
                if (val <= cur_v) break;
                rightward[idx] = i - idx;
                stack.pop_back();
            }
            stack.emplace_back(i, cur_v);
        }
        while (!stack.empty()) {
            const auto [idx, val] = stack.back();
            rightward[idx] = length - idx;
            stack.pop_back();
        }
        // 向左
        stack.emplace_back(length - 1, heights.back());
        for (int i = length - 2; i >= 0; i--) {
            int cur_v = heights[i];
            while (!stack.empty()) {
                const auto [idx, val] = stack.back();
                if (val <= cur_v) break;
                leftward[idx] = idx - i;
                stack.pop_back();
            }
            stack.emplace_back(i, cur_v);
        }
        while (!stack.empty()) {
            const auto [idx, val] = stack.back();
            leftward[idx] = idx + 1;
            stack.pop_back();
        }
        int max_area = 0;
        for (int i = 0; i < length; i++) {
            max_area = std::max(max_area, heights[i] * (leftward[i] + rightward[i] - 1));
        }
        return max_area;
    }
};

int main(int argc, char** argv) {
    Solution sol;

    return 0;
}