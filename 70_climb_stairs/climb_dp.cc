#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <unordered_map>
#include <unordered_set>

using namespace std;

/**
 * 最简单的动态规划题，动态规划攻坚 --- 起始
 * 我对动态规划的理解就是：状态转移，尝试将问题转化为子问题
 * 但有的时候，状态转移写得不好，或者没思路，或者没看出来这是个状态转移问题，就写不出来
 * 所以需要训练，有这个意识
 * 
 * 官方题解说了一种叫矩阵快速幂优化的东西
 * runtime: 100.00%
 * memory:  25.77%
 */
class Solution {
public:
    int climbStairs(int n) {
        if (n <= 2) return n == 1 ? 1 : 2;          // n = 2 时只有两种爬楼梯方法
        // 本题应该可以使用 O(1) 复杂度做出来
        int prev_2 = 1, prev_1 = 2, cnt = 2;
        for (;cnt < n; cnt++) {
            int new_ways = prev_1 + prev_2;
            prev_2 = prev_1;
            prev_1 = new_ways;
        }
        return prev_1;
    }
};

int main(int argc, char** argv) {
    Solution sol;

    return 0;
}