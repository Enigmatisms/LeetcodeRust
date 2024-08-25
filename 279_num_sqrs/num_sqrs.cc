#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <unordered_map>
#include <unordered_set>

using namespace std;

/**
 * 这道题 是一个背包问题... 而且还是: 求最少放多少物品可以
 * 恰好装满背包 同一个物体可以选很多次 可没有那么好欺负哦
 * 子问题：
 * runtime: 52.44%
 * memory:  32.74%
 */
class Solution {
public:
    int numSquares(int n) {
        std::vector<int> dp = {0, 1, 2, 3, 1, 2, 3, 4, 2, 1};    // remaining room 1 - 7
        if (n <= 9) return dp[n];
        dp.resize(n + 1);
        for (int i = 10; i <= n; i++) {
            int min_val = 10001;
            for (int j = 1; j * j <= i; ++j) {
                min_val = std::min(min_val, dp[i - j * j] + 1);
            }
            dp[i] = min_val;
        }
        return dp.back();
    }
};

// 可以不用这个，但是这也算提供了一种整数平方根的求法
int sqrt_int(int x) {
    if (x == 0 || x == 1) return x;

    int left = 1, right = x, result = 0;
    while (left <= right) {
        int mid = (right + left) >> 1;
        if (mid <= x / mid) {
            result = mid;
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return result;
}

int main(int argc, char** argv) {
    Solution sol;
    std::cout << sqrt_int(atoi(argv[1])) << std::endl;
    return 0;
}