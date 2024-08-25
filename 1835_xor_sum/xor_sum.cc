#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <unordered_map>
#include <unordered_set>

using namespace std;

/**
 * 这道题... 一看到就要有这样的一个思想
 * 这么多数字，肯定不能直接枚举，那能不能一位一位操作？每次计算一位的结果？
 * 可以回顾 137 (只出现一次的数字 II), 答案是 32 位整数，那么我们可以尝试一位一位计算
 * 为什么可以一位一位计算？这种位运算的题目需要特别注意：AND, OR, XOR 这些都只操作本位
 * 不会对其他位产生影响（而相反，加减法由于存在进位退位所以不行）
 * 
 * 本题的思路: 每一位先统计会有多少个 and 为 1, 这些为 1 的 and 需要进行 xor, 而根据 XOR
 * 的性质：偶数 0 奇数 1
 * runtime: 41.27%
 * memory:  25.40%
 */
class Solution {
public:
    int getXORSum(vector<int>& arr1, vector<int>& arr2) {
        int result = 0;
        for (int i = 0, extractor = 1; i < 32; i++, extractor <<= 1) {
            int cnt1 = 0, cnt2 = 0;
            for (int v: arr1)
                cnt1 += (extractor & v) > 0;
            for (int v: arr2)
                cnt2 += (extractor & v) > 0;
            if ((cnt1 & 1) & (cnt2 & 1)) {      // all odd
                result += 1 << i;
            }
        }
        return result;
    }
};

int main(int argc, char** argv) {
    Solution sol;

    return 0;
}