#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <unordered_map>
#include <unordered_set>

using namespace std;

/**
 * 贪心算法：每次选择最小的，与最大（可能的），进行位交换
 * 1 与 2^p - 2, --> 0, 2^p - 1
 * 2 与 2^p - 3, --> 0, 2^p - 1
 * ... 实际上，2^p - 1 到 1 一共有 2^p - 1 个数字 (奇数)，除了中间那个数之外
 * 前后都可以两两匹配成 2^p - 1 (相加)
 * 将 2^p - 1 匀出一个1 来，填补原来的 0，则我们有：
 * 2^(p-1) - 1 个 2^p - 2 (以及 1) 以及一个2^(p-1)
 * 主要是能不能想到这个贪心的思路
 * 这个实现也挺恶心我的。注意如下要点：
 * 1. 如果不好把握是否会超界，就直接 long long, 不必为了省什么而写容易错的 int (现在计算机都 64 位了)
 * 2. fast_pow 中，指数(pow) 不要取余，否则会改变结果
 * 3. 为什么可以一边乘一边取余？为什么与乘完取余效果一致？这个规律很简单
 * A mod M = C, 则 A = KM + C, A * C mod M = (KM + C) * C mod M = C^2 mod M
 * 同理，A^3 mod M = C^3 mod M，反正取余是可以在连乘前或者后的
 * runtime: 100.00%
 * memory:  44.19%
 */
constexpr long long MOD_VAL = 1e9 + 7;
class Solution {
public:
    long long fast_pow(long long a, long long pow) {

        long long result = 1;
        while (pow) {
            if (pow & 1) {
                result *= a;
                if (result > INT32_MAX)
                    result %= MOD_VAL;
            }
            a *= a;
            if (a > INT32_MAX)
                a %= MOD_VAL;
            pow >>= 1;
        }
        return result;
    }

    int minNonZeroProduct(int p) {
        if (p == 1) return 1;
        long long p_2pow_2 = (1ll << p) % MOD_VAL - 2, p_1_2pow = 1ll << (p - 1);
        long long v1 = fast_pow(p_2pow_2, p_1_2pow - 1) * (p_2pow_2 + 1);
        return v1 % MOD_VAL;
    }
};

int main(int argc, char** argv) {
    Solution sol;

    return 0;
}