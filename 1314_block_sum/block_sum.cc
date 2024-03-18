#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <unordered_map>
#include <unordered_set>

using namespace std;

/**
 * 每日一题是用前缀和加速的简单题，这是一道二维前缀和的题
 * 显然如果我们用暴力法... 会很暴力
 * 二维前缀和就很简单：假设矩阵为 (r, t) 到 (l, b) 的
 * 实际值求解: pre[r, t] - pre[r, b] - pre[l, t] + pre[l, b] (重复减)
 * 求解2D前缀和不要搞错了
 * runtime: 94.16%
 * memory:  48.60%
 */
class Solution {
public:
    vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int k) {
        int rows = mat.size(), cols = mat[0].size();
        std::vector<int> prefix_sum(rows * cols, 0);      // memory bound, therefore linearize
        prefix_sum[0] = mat[0][0];
        for (int c = 1; c < cols; c++) 
            prefix_sum[c] = mat[0][c] + prefix_sum[c - 1];
        for (int r = 1; r < rows; r++) {
            int base = r * cols, prev_base = base - cols;
            prefix_sum[base] = mat[r][0];
            for (int c = 1; c < cols; c++) {
                prefix_sum[base + c] = prefix_sum[base + c - 1] + mat[r][c];
                prefix_sum[base + c - 1] += prefix_sum[prev_base + c - 1];
            }
            prefix_sum[base + cols - 1] += prefix_sum[prev_base + cols - 1];
        }

        std::vector<std::vector<int>> result(rows, std::vector<int>(cols, 0));
        for (int r = 0; r < rows; r++) {
            int r_max = std::min(r + k, rows - 1) * cols, r_min = (r - k - 1) * cols;
            bool valid_r = r_min >= 0;
            for (int c = 0; c < cols; c++) {
                int c_max = std::min(c + k, cols - 1), c_min = c - k - 1;
                bool valid_c = c_min >= 0;
                int cur_val = prefix_sum[r_max + c_max];
                if (valid_r)
                    cur_val -= prefix_sum[r_min + c_max];
                if (valid_c)
                    cur_val -= prefix_sum[r_max + c_min];
                if (valid_r && valid_c)
                    cur_val += prefix_sum[r_min + c_min];
                result[r][c] = cur_val;
            }
        }
        return result;
    }
};

int main(int argc, char** argv) {
    Solution sol;

    return 0;
}