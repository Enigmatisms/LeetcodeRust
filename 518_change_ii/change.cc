#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <unordered_map>
#include <unordered_set>

using namespace std;

/**
 * 昨日每日一题的进阶
 * 也是背包问题，但是要返回组合数，看如何设计DP 我觉得很简单
 * ... 嗯 能想到这是DP,脑子正常点都能想到
 * 结果在实际实现的时候卡住了：一开始在外层是 1 到 amount 循环，内层是 coin 循环，这就会导致重复记录
 * 分析一下：如果是外层 1 到 amount 循环，记录的实际上是
 * [元素间记录不同排列，相同元素只记录组合]的数量
 * 如果换一下循环顺序，虽然乍一看没那么直观，仔细想的话还是挺合理的
 * 不同面额的硬币在结果中的位置是确定的（并且相同面额的将会在一起）
 * 比如，5, [1, 2, 5]，先是1，则有:
 * 0 (1), 1 (1), 1 + 1 (1), 1 + 1 + 1 (1), 1 + 1 + 1 + 1 (1), 1 * 5 (1) ---> 只使用1
 * 0 (1), 1 (1), [1+1, 2] (2), [1+1+1, 1+2] (2), [1+1+1+1,1+1+2,2+2] (3), [1*5,1+1+1+2,1+2+2] (3) ---> 使用1 与 2
 * 这样逐步开放，可以避免在内层循环时，多次循环到对应的面额得到不同的排列
 * 
 * 总之，关注循环顺序。不要落到 DP 定死的套路里，DP 可以很灵活。
 * runtime: 77.53%
 * memory:  58.13%
 */
class Solution {
public:
    int change(int amount, vector<int>& coins) {
        if (amount == 0) return 1;
        std::vector<int> dp(amount + 1, 0);
        dp[0] = 1;
        for (int coin: coins) {
            for (int i = 1; i <= amount; ++i) {
                if (i - coin < 0) continue;
                dp[i] += dp[i - coin];
            }
        }
        return dp.back();
    }
};

int main(int argc, char** argv) {
    Solution sol;

    std::vector<int> coins{1, 2, 5};
    sol.change(5, coins);
    return 0;
}