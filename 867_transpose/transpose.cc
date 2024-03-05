#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <unordered_map>
#include <unordered_set>

using namespace std;

/**
 * runtime: 99.16%
 * memory:  27.96%
 */
class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& matrix) {
        size_t row = matrix.size(), col = matrix[0].size();
        std::vector<std::vector<int>> result(col, std::vector<int>(row, 0));
        for (size_t i = 0; i < row; i++) {
            const auto& origin_row = matrix[i];
            for (size_t j = 0; j < col; j++) {
                result[j][i] = origin_row[j];
            }
        }
        return result;
    }
};

int main(int argc, char** argv) {
    Solution sol;

    return 0;
}