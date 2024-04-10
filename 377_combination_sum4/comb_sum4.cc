#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <unordered_map>
#include <unordered_set>

using namespace std;

/**
 * 背包问题都是套路啊
 * 
 * (1) DP 数组含义
 * DP[k][i] 表示开放前 k 个数，总和为 i 的组合数量
 * (2) 递推公式
 * DP[k][i] 的 reduce 模式是 sum, 不是 max，所以
 * DP[k][i] = DP[k - 1][i] + DP[k - 1][i - nums[k]]
 * 不过注意，由于是可重复的，注意遍历顺序
 * (3) 初始化
 * DP[0][i] 在每次 i 为 nums[0] 整数倍时，都等于 1
 * (4) 空间复杂度优化
 * 显然可以
 * runtime: 100.00%
 * memory:  27.86%
 * 
 * 这道题的坑点有两个
 * (1) 说是组合，实际上求的是不同元素的排列
 * 
 * 注意循环顺序！在合适的使用合适的循环顺序。一般可以这么理解：
 * 1. 内层循环对物品进行遍历（相当于多次遍历物品），一般用于求排列
 * 2. 外层循环遍历物品（物品只遍历一次），一般用于求组合
 * 
 * (2) 组合爆炸！ 见下面的用例。如果不mod，会炸掉。
 * 官方真的，这道题官解真的不讲武德
 */
constexpr int MOD = INT32_MAX;
class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        int num_size = nums.size();
        if (num_size == 1)
            return (target % nums[0]) == 0;     // if target sum 
        std::vector<long long> dp(target + 1, 0);
        dp[0] = 1;
        // 思路是没问题的，但是... 10 20 30 这样的存在会导致组合爆炸
        for (int i = 1; i <= target; i++) {
            for (int num: nums) {
                if (i < num) continue;
                dp[i] = (dp[i] + dp[i - num]) % MOD;
            }
        }
        return dp.back();
    }

    // 我这是真正的组合，但... 题目要求的好像是要排列？
    int combinationSum4_false(vector<int>& nums, int target) {
        int num_size = nums.size(), num = nums[0];
        if (num_size == 1)
            return (target % num) == 0;     // if target sum 
        std::vector<long long> dp(target + 1, 0);
        dp[0] = 1;
        for (int i = num; i <= target; i += num)
            dp[i] = 1;
        // 只算了 (1, 2)，没有算 (2, 1) 情况
        // 所以，我怀疑可能内外层循环需要换
        for (int k = 1; k < num_size; k++) {
            num = nums[k];
            for (int i = num; i <= target; i++)
                dp[i] += dp[i - num];
        }
        return dp.back();
    }
};

int main(int argc, char** argv) {
    Solution sol;
    std::vector<int> vec = {10,20,30,40,50,60,70,80,90,100,110,120,130,140,150,160,170,180,190,200,210,220,230,240,250,260,270,280,290,300,310,320,330,340,350,360,370,380,390,400,410,420,430,440,450,460,470,480,490,500,510,520,530,540,550,560,570,580,590,600,610,620,630,640,650,660,670,680,690,700,710,720,730,740,750,760,770,780,790,800,810,820,830,840,850,860,870,880,890,900,910,920,930,940,950,960,970,980,990,111};
    std::cout << sol.combinationSum4(vec, 999) << std::endl;
    return 0;
}