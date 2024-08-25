#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <unordered_map>
#include <unordered_set>

using namespace std;

/**
 * runtime: 79.18%
 * memory:  14.65%
 */
class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        size_t cols = matrix[0].size();
        for (size_t i = 1; i < matrix.size(); i++) {
            const std::vector<int>& this_row = matrix[i];
            const std::vector<int>& last_row = matrix[i - 1];
            for (size_t j = 1; j < cols; j++) {
                if (this_row[j] == last_row[j - 1]) continue;
                return false;
            }
        }
        return true;
    }
};

int main(int argc, char** argv) {
    Solution sol;

    return 0;
}