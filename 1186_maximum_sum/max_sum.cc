#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/**
 * 感觉是一个双指针题目
 * 即：右指针一直向前指，如果遇到大于等于两个负数时，左指针移动
 * 但是错了
 * 
 * 可以全部加起来去掉最小的那个（有用例如此，我没有考虑）
 * 这道题要动态规划吧 果然 (太久没有做DP题，想得很复杂)
 * 
 * 不需要考虑起始，只需要考虑结尾，这是一个经典决策（根据决策划分多个数组）
 * 1. DP 数组含义
 * DP[i][决策（二元）]有
 * DP[i][0] 表示最大探查长度在 arr[i] (包括)，且没有删除的   --- 最大结果
 * DP[i][j] 表示最大探查长度在 arr[i] (包括)，且已经删除过的 --- 最大结果
 * 
 * 2. 递推
 * 记住 DP[i][0] 总是没有删除，所以其只能是 DP[i + 1][0] = max(DP[i][0], 0) + arr[i + 1]
 * 解释：如果 arr[i + 1] 大于 0，且前面的结果都是负，那这次前面的都会被丢弃，反之如果 arr 小于 0，则要么
 * 选负 绝对值小的，要么在之前的结果上累加负数（因为不能删）
 * 
 * DP[i + 1][1] 则 max(DP[i][1] + arr[i + 1], DP[i][0])
 * 解释：DP[i][1] + arr[i + 1] 表示：之前删除了，这次不能删，没有选择，只能累加
 * DP[i][0] 表示：我删掉了 arr[i + 1]
 * 
 * 3. 初始值
 * DP[0][0] = arr[0]
 * DP[0][1] = 0
 * 
 * 4. 是否可以空间优化？
 * 当然，只需要两个之前状态值就可
 * 
 * 所以为什么可以不用考虑起始？DP[i][0] 其实一直在考虑，如果前面一直是负，那么DP[i][0] 将一直 clamp
 * runtime: 97.02%
 * memory:  70.86%
 */
class Solution {
public:
    int maximumSum(vector<int>& arr) {
        int dp_prev_0 = arr[0], dp_prev_1 = 0, max_val = dp_prev_0;
        for (size_t i = 1; i < arr.size(); i++) {
            int arr_i = arr[i];
            dp_prev_1 = std::max(dp_prev_1 + arr_i, dp_prev_0);
            dp_prev_0 = std::max(dp_prev_0, 0) + arr_i;
            max_val   = std::max(std::max(dp_prev_0, dp_prev_1), max_val);
        }
        return max_val;
    }

    // 错误解答
    int maximumSumFalse(vector<int>& arr) {
        int lp = 0, sum = 0, last_neg = -1, max_sum = -1e4;
        for (int i = 0; i < arr.size(); i++) {
            int v = arr[i];
            if (v < 0) {
                max_sum = std::max(max_sum, v);
                if (last_neg < 0) {
                    last_neg = i;
                    continue;
                }
                // 如果已经存在一个负数了：左指针移动到 last_neg + 1
                // 且 sum 减去路上所有的正数
                for (; lp < last_neg; lp++) 
                    sum -= arr[lp];
                lp = last_neg + 1;
                last_neg = i;
            } else {
                sum += v;
                max_sum = std::max(sum, max_sum);
            }
        }
        return max_sum;
    }
};

int main(int argc, char** argv) {
    Solution sol;

    return 0;
}