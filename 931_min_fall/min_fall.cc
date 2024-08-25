#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <unordered_map>
#include <unordered_set>

using namespace std;

/**
 * runtime: 84.80%
 * memory:  15.10%
 */
class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int num_rows = static_cast<int>(matrix.size()), num_cols = static_cast<int>(matrix.front().size());
        std::vector<int> costs = matrix.back();
        for (int i = num_rows - 2; i >= 0; i--) {
            std::vector<int> new_costs(num_cols, 0);
            for (int j = 1; j < num_cols - 1; j++) {
                new_costs[j] = matrix[i][j] + std::min(
                    std::min(costs[j - 1], costs[j]), std::min(costs[j], costs[j + 1])
                );
            }
            new_costs.front() = matrix[i].front() + std::min(costs.front(), costs[1]);
            new_costs.back()  = matrix[i].back()  + std::min(costs.back(), *(costs.crbegin() + 1));
            costs = std::move(new_costs);
        }
        return *std::min_element(costs.cbegin(), costs.cend());
    }
};

int main(int argc, char** argv) {
    Solution sol;

    return 0;
}