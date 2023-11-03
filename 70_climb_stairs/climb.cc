#include <iostream>

/**
 * 不愧是简单题，逆天简单。就是组合数防溢出计算需要温习一下
 * runtime: 100.00%
 * memory:  24.16%  (为什么呢)
 * @param n 
 * @param r 
 * @return uint64_t 
 */

inline uint64_t C(uint64_t n, uint64_t r) 
{
    uint64_t f = 1;
    for(auto i = 0; i < r; i++)
        f = (f * (n - i)) / (i + 1);
    return f; 
}

class Solution {
public:
    // 排列组合问题：多少个2，多少个1，全排列 除以 2全排列 除以 1全排列？
    int climbStairs(int n) {
        int max_num2 = n >> 1;
        int res = 0;
        for (int i = 0; i <= max_num2; i++) {
            int num_1 = n - (i << 1);
            int total_num = num_1 + i;
            res += static_cast<int>(C(total_num, num_1));
        }
        return res;
    }
};

int main(int argc, char** argv) {
    int num_stairs = atoi(argv[1]);
    Solution sol;
    printf("%d stairs, result = %d\n", num_stairs, sol.climbStairs(num_stairs));
    return 0;
}