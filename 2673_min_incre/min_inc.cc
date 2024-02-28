#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/**
 * 
 * runtime: 81.13%
 * memory:  
 */
class Solution {
public:
    int minIncrements(int n, vector<int>& cost) {
        std::vector<int> max_val(cost.size());
        max_tree_val(cost, max_val, 0);
        return solve_recursive(cost, max_val, max_val[0], 0);
    }

    int solve_recursive(const std::vector<int>& costs, const std::vector<int>& max_val, int target, int index) {
        int cur_diff = target - max_val[index];
        int next_index = index * 2 + 1;
        if (next_index >= costs.size()) return cur_diff;
        int next_target = target - cur_diff - costs[index];
        cur_diff += solve_recursive(costs, max_val, next_target, next_index);
        cur_diff += solve_recursive(costs, max_val, next_target, next_index + 1);
        return cur_diff;
    }

    void max_tree_val(const std::vector<int>& costs, std::vector<int>& max_val, int index) {       // left (2n + 1), right (2n + 2)
        int next_index = index * 2 + 1;
        if (next_index >= costs.size()) {
            max_val[index] = costs[index];
            return;
        }
        max_tree_val(costs, max_val, next_index);            // l-tree
        max_tree_val(costs, max_val, next_index + 1);            // r-tree
        max_val[index] = std::max(max_val[next_index], max_val[next_index + 1]) + costs[index];
    }
};

int main(int argc, char** argv) {
    Solution sol;

    return 0;
}