#include <vector>
#include <iostream>

/**
 * 这题很有意思，对于给定的 m / n，暴力法递归肯定可以做（只要不超时）
 * 但稍加推导可以发现，本题与杨辉三角有关，所求的实际上是某情况下杨辉三角的通项公式
 * 也即本问题是有解析解的，无需算法。由于需要计算阶乘，时间复杂度为 O(n)，空间复杂度O(1)
 * 但很可惜，本问题很容易溢出：阶乘太大，需要特殊的计算阶乘方法并且将位数提高
 * runtime: 100%
 * memory: 71.6%
 * 但其实，题解有写得更加明了的：直接组合解：因为机器到底右下角，向下几步，向右几步都是固定的
 * 所以实际上是直接的组合问题
 */

uint64_t choose(uint64_t n, uint64_t k) {
    uint64_t r = 1;
    uint64_t d;
    if (k > n) return 0;
    for (d=1; d <= k; d++) {
    r *= n--;
    r /= d;
    }
    return r;
}

class Solution {
public:
    int uniquePaths(int m, int n) {
        // make sure m > n
        if (m < n) std::swap(m, n);
        if (n > 3) {
            m = m + n - 2;
            return static_cast<int>(choose(m, n-1));
        } else if (n == 3) {
            return m * (m + 1) / 2;
        } else if (n == 2) {
            return m;
        } else {
            return 1;
        }
    }
};

int main(int argc, char** argv) {
    int m = 4, n = 7;
    if (argc > 2) {
        m = atoi(argv[1]);
        n = atoi(argv[2]);
    }
    Solution sol;
    printf("m = %d, n = %d, result = %d\n", m, n, sol.uniquePaths(m, n));
    return 0;
}