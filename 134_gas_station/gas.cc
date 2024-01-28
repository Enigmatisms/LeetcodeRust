#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;

/**
 * 有些题目... 需要寻找内部隐藏的规律。比如本题，直接想方法很难想到
 * 本题需要找到这样一个规律：如果从加油站i出发，到j后恰好无法继续
 * 则 [i, j] 内其他加油站都无法到 j 的下一个加油站，则可以直接跳过
 * 怎么说呢，这让我想到KMP这种非回退式的方法，我之前一直以为要回退。但实际上
 * 可以找到一种不回退的线性方法。遇到这样的题（规律：向前查找按要求“匹配”，若遇到不符合要求的
 * 可能“需要回退”）时需要找规律：是否可以不回退？
 * runtime: 98.91%
 * memory:  21.13%
 */
class Solution {
public:
    int canCompleteCircuit(const vector<int>& gas, const vector<int>& cost) const noexcept {
        int num_cities = gas.size(), ptr = 0;
        while (ptr < num_cities) {
            int sum_gas = 0, sum_cost = 0, cnt = 0;
            for (; cnt < num_cities; cnt++) {
                int new_ptr = ptr + cnt;
                if (new_ptr >= num_cities) new_ptr -= num_cities;
                sum_gas += gas[new_ptr];
                sum_cost += cost[new_ptr];
                if (sum_cost > sum_gas) break;
            }
            if (cnt == num_cities) return ptr;
            ptr += cnt + 1;
        }
        return -1;
    }
};

int main(int argc, char** argv) {
    Solution sol;

    return 0;
}