#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <unordered_map>
#include <unordered_set>

/**
 * 对matrix的表示问题不够熟悉...
 * runtime: 25.68%
 * memory:  5.24%
 */
class Solution {
using RowVec = std::vector<int>;
using Matrix = std::vector<RowVec>;
public:
    int tribonacci(int n) {
        if (n <= 2) {
            switch (n) {
                case 2: return 1;
                case 1: return 1;
                case 0: return 0;
            }
        }
        Matrix transit = {{1, 1, 1}, {1, 0, 0}, {0, 1, 0}};
        Matrix mult_trans = matrix_power(std::move(transit), n - 2);
        return mult_trans[0][0] + mult_trans[0][1];
    }

    Matrix matrix_power(Matrix&& mat, int pow_n) const {
        Matrix result = {{1, 0, 0}, {0, 1, 0}, {0, 0, 1}}, cur = std::move(mat);
        while (true) {
            if (pow_n & 1) {
                result = multiply(result, cur);
            }
            pow_n >>= 1;
            if (!pow_n) break;
            cur    = multiply(cur, cur);
        }
        return result;
    }

    Matrix multiply(const Matrix& m1, const Matrix& m2) const {
        Matrix result(3, {0, 0, 0});
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                result[i][j] = m1[i][0] * m2[0][j] + m1[i][1] * m2[1][j] + m1[i][2] * m2[2][j];
            }
        }
        return result;
    }
};

int main(int argc, char** argv) {
    Solution sol;

    return 0;
}