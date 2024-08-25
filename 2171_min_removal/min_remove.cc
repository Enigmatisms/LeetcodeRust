#include <vector>
#include <algorithm>
#include <iostream>

/**
 * 我感觉这道题很简单？ 太简单了，思路一下就能想到，写这道题用了5min，一遍AC：
 *      argmin(v) <- $\sum_{v_i \geq v} (v_i - v) + \sum_{v_i < v} v_i$
 *      等价于: argmax(v) v * #{v_i \geq v}
 * runtime: 93.1%
 * memory:  29.88%
 */
class Solution {
public:
    long long minimumRemoval(std::vector<int>& beans) {
        std::sort(beans.begin(), beans.end());
        long long max_size = beans.size();
        int last_value = beans.front();
        long long sum = last_value, max_retain = sum * max_size;
        for (long long i = 1; i < max_size; i++) {
            long long this_value = static_cast<long long>(beans[i]);
            sum += this_value;
            if (this_value == last_value) continue;
            max_retain = std::max((max_size - i) * this_value, max_retain);
        }
        return sum - max_retain;
    }
};

int main(int argc, char** argv) {
    Solution sol;

    return 0;
}