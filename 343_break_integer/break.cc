#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/**
 * 我能确定的是：这些整数都比较接近（根据平方平均和算数平均的关系）
 * 但这种想法无助于做题（可能可以出一种解，但是我们最好还是尝试用 DP）
 * (1) 确定 DP 数组以及下标含义。目前我的想法：
 * DP[i] 表示和为 i 的数的最大乘积
 * (2) 确定递推公式
 * DP[i] 应该会等于 max(DP[i - val] * val), for val in [1, i - 1]
 * 漏了情况，比如 4 = 2 + 2 -> 2 * 2, 按上述方法考虑，会出现：
 * DP[4] = max(DP[4 - i] * i), 结果最大也就是 3
 * 具体是什么地方出错了？少考虑了一种情况：
 * (i - j) * j，个人感觉直接按 DP 思路走很容易丢掉这种本应该很容易想到的情况
 * max_prod[i - j] 是可能会小于 i - j 的，所以必须要额外考虑
 * (3) 边界条件
 * DP[0] = 0
 * DP[1] = 1
 * DP[2] = 1
 * DP[3] = 2
 * (4) 空间复杂度优化：不可优化
 * (5) 时间复杂度优化：已知内层需要 for，此部分无法优化，复杂度固定 O(n^2)
 * 
 * 本题启发：需要把可以获得当前 DP 的所有渠道都想清楚（递推公式要全面）
 * runtime: 100.00%
 * memory:  51.17%
 */
class Solution {
public:
    int integerBreak(int n) {
        if (n <= 3) return n - 1;
        std::vector<int> max_prod(n + 1, 1);
        max_prod[3] = 2;
        for (int i = 4; i <= n; i++) {
            int prod = std::max(max_prod[i - 1], i - 1);
            for (int j = 2; j < i - 1; j++) {
                prod = std::max(prod, max_prod[i - j] * j);
                prod = std::max(prod, (i - j) * j);
            }
            max_prod[i] = prod;
        }
        return max_prod.back();
    }
};

int main(int argc, char** argv) {
    Solution sol;
    sol.integerBreak(11);
    return 0;
}