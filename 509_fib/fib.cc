#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <numeric>
#include <unordered_map>
#include <unordered_set>

using namespace std;

/**
 * 矩阵优化 O(logN) 复杂度，很有趣，但同时也很奇怪
 * 写不出通项公式并且状态转移可以化为简单的线性公式时，就可以用矩阵
 * runtime: 100%
 * memory:  5.06%
 */
constexpr float sqrt5 = 2.23606797749979;
class Solution {
public:
    int fib(int n) {
        float fibN = powf((1 + sqrt5) / 2, n) - powf((1 - sqrt5) / 2, n);
        return roundf(fibN / sqrt5);
    }
};

int main(int argc, char** argv) {
    Solution sol;

    return 0;
}