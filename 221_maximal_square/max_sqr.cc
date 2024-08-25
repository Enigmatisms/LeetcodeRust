#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <unordered_map>
#include <unordered_set>

using namespace std;

/**
 * 初见时：这tm和动态规划有毛关系？
 * 这道题动态规划问题构建... 比较难想。这道题很有意思：当前位置(i, j) 可以组成的最大正方形边长实际上会被
 * (i - 1, j) (i - 1, j - 1) (i, j - 1) 三处的值制约，至于为什么，画个图看看就知道了。
 * 这道题与1277有联系
 * runtime: 96.98%
 * memory:  35.68%
 */
class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        short num_rows = static_cast<short>(matrix.size()), num_cols = static_cast<short>(matrix.front().size()), max_score = 0;
        std::vector<short> score(num_cols, 0);
        for (short i = 0; i < num_cols; i++) {
            if (matrix.front()[i] > '0') {
                max_score = 1; 
                score[i] = 1;
            }
        }
        for (short row = 1; row < num_rows; row++) {
            std::vector<short> new_score(num_cols, 0);
            if (matrix[row].front() > '0') {
                max_score         = std::max(static_cast<short>(1), max_score);
                new_score.front() = 1;
            }
            for (short col = 1; col < num_cols; col++) {
                if (matrix[row][col] == '0') continue;
                short cur_val  = 1 + std::min(std::min(new_score[col - 1], score[col - 1]), std::min(score[col - 1], score[col]));
                max_score      = std::max(cur_val, max_score);
                new_score[col] = cur_val;
            }
            score = std::move(new_score);
        }
        return max_score * max_score;
    }
};

short main(short argc, char** argv) {
    Solution sol;

    return 0;
}