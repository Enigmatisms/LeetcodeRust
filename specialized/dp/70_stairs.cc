#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/**
 * leetcode 70: 每次可以爬 1 或 2级，则到顶最多有多少种爬梯方法？
 * (1) 确定 DP 数组以及下标含义
 * DP[i] 表示楼梯有 i 级时，有 DP[i] 种方法
 * (2) 确定递推关系
 * 不同级之间有什么关系？
 * 乍一看：
 * i - 1 到 i 只有一种方法, i - 2 到 i 有两种（一次两级，或者两次一级）
 * 所以：DP[i] = max(DP[i - 1] + 1, DP[i - 2] + 2);
 * 但实际上不是这样的：
 * 从 i - 1 到 i 只有一种可能，所以 i - 1 有多少种，多走一步，形成了部分 i
 * 从 i - 2 到 i 我们可以有两种方式: (1) 一次走两步 （2）先走一步，再走一步
 * 但是 (2) 实际上会和 i - 1 算重复的结果。所以我们智能考虑 (1)，故实际上是
 * DP[i] = DP[i - 1] * 1 + DP[i - 2] * 1
 * 这tm不是斐波那契吗？
 * (3) 确定边界
 * DP[0] = 0, DP[1] = 1, DP[2] = 2 (都很显然)
 * (4) 确定空间优化的可能
 * 显然，我们只需要记录 i 之前的两个状态，所以空间复杂度是 O(1)
 * 
 * 可以开干。
 * runtime: 100.00%
 * memory:  74.84%
 * 
 * 这道题乍一眼看的递推是有问题的，为什么我一开始会这么想？
 * 这里涉及到一个 reduce 问题：DP 当前的状态都是由之前的状态 reduce 得到的
 * 怎么 reduce 是个问题。本题理解错了意思：不是问最多多少（max），而是问一共多少（sum）
 */
class Solution {
public:
    int climbStairs(int n) const {
        if (n <= 2) return n;
        int prev_2 = 1, prev_1 = 2, cur = 0;
        for (int i = 3; i <= n; i++) {
            cur = prev_1 + prev_2;
            prev_2 = prev_1;
            prev_1 = cur;
        }
        return cur;
    }
};


int main(int argc, char** argv) {
    Solution sol;

    return 0;
}