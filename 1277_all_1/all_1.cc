#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <unordered_map>
#include <unordered_set>

using namespace std;

/**
 * runtime: 93.16%
 * memory:  36.42%
 */
class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        short num_rows = static_cast<short>(matrix.size()), num_cols = static_cast<short>(matrix.front().size());
        std::vector<short> score(num_cols, 0);
        std::vector<int> num_sqrs(4, 0);            // number of squares
        for (short i = 0; i < num_cols; i++) {
            if (matrix.front()[i]) {
                num_sqrs.front() ++;
                score[i] = 1;
            }
        }
        for (int row = 1; row < num_rows; row++) {
            std::vector<short> new_score(num_cols, 0);
            if (matrix[row].front()) {
                num_sqrs.front() ++;
                new_score.front() = 1;
            }
            for (int col = 1; col < num_cols; col++) {
                if (matrix[row][col] == 0) 
                    continue;
                int cur_val = 1 + std::min(std::min(new_score[col - 1], score[col - 1]), std::min(score[col - 1], score[col]));
                for (int j = cur_val - 1; j >= 0; j--) {
                    if (j > num_sqrs.size())
                        num_sqrs.push_back(1);
                    else 
                        num_sqrs[j] ++;
                }
                new_score[col] = cur_val;
            }
            score = std::move(new_score);
        }
        return std::accumulate(num_sqrs.cbegin(), num_sqrs.cend(), 0);
    }
};

int main(int argc, char** argv) {
    Solution sol;

    return 0;
}