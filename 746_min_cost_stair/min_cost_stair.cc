#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <unordered_map>
#include <unordered_set>

using namespace std;

/**
 * 这题同样也很简单... 毕竟是简单题嘛
 * runtime: 100.00%
 * memory:  22.61%
 */
class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        if (cost.size() < 3) return cost.front() <= cost.back() ? cost.front() : cost.back();
        int step_a = *(cost.crbegin() + 1), step_b = cost.back(), length = static_cast<int>(cost.size());
        for (int cnt = 2; cnt < length; cnt++) {
            int cur_cost = cost[length - cnt - 1] + std::min(step_a, step_b);
            step_b = step_a;
            step_a = cur_cost;
        }
        return std::min(step_a, step_b);
    }
};

int main(int argc, char** argv) {
    Solution sol;

    return 0;
}