#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <unordered_map>
#include <unordered_set>

using namespace std;

/**
 * 二维差分，推了10min... 菜狗
 * runtime: 63.33%
 * memory:  86.00%
 */
class Solution {
public:
    vector<vector<int>> rangeAddQueries(int n, vector<vector<int>>& queries) {
        vector<vector<int>> mat(n, std::vector<int>(n, 0));
        for (const auto& q: queries) {
            int sr = q[0], sc = q[1], er = q[2], ec = q[3];
            for (int row = sr; row <= er; row++) {
                ++ mat[row][sc];
            }
            if (ec < n - 1) {
                for (int row = sr; row <= er; row++) {
                    -- mat[row][ec + 1];
                }
            }
        }
        for (auto& row: mat)
            std::partial_sum(row.begin(), row.end(), row.begin());
        return mat;
    }
};

int main(int argc, char** argv) {
    Solution sol;

    return 0;
}