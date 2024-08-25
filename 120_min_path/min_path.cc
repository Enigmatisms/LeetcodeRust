#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <unordered_map>
#include <unordered_set>

using namespace std;

/**
 * runtime: 91.92%
 * memory:  36.73%
 */
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int tri_size = static_cast<int>(triangle.size());
        if (tri_size == 1) return triangle.front().front();
        std::vector<int> costs = triangle.back();
        for (int i = tri_size - 2; i >= 0; i--) {
            for (int j = 0; j <= i; j++) {
                costs[j] = triangle[i][j] + std::min(costs[j], costs[j + 1]);
            }
        }
        return costs.front();
    }
};

int main(int argc, char** argv) {
    Solution sol;

    return 0;
}