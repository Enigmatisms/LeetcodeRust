#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <unordered_map>
#include <unordered_set>

using namespace std;


/**
 * 本题思路真不难，连想带做10min左右即可
 * runtime: 100.00%
 * memory:  32.95%
 */
constexpr long long MOD = 1e9 + 7;
class Solution {
public:
    int minimumPossibleSum(int n, int target) {
        if (n == 1) return 1;
        long long nl = static_cast<long long>(n); 
        if (2 * n - 1 < target) 
            return static_cast<int>((n * (n + 1) >> 1) % MOD);
        
        long long un_max = ((target + 1) >> 1) - (target & 1), new_num = nl - un_max;
        long long result = ((1 + un_max) * un_max >> 1) + ((2 * target + new_num - 1) * new_num >> 1);
        return static_cast<int>(result % MOD);
    }
};

int main(int argc, char** argv) {
    Solution sol;
    int n = atoi(argv[1]);
    int t = atoi(argv[2]);
    int res = sol.minimumPossibleSum(n, t);
    printf("n = %d, target = %d, result = %d\n", n, t, res);
    return 0;
}