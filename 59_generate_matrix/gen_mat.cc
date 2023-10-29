/**
 * Easy
 * runtime: 100.00%
 * memory:  23.49%
*/

#include <vector>
#include <iostream>

class Solution {
using Array  = std::vector<int>;
using Arrays = std::vector<Array>;
public:
    Arrays generateMatrix(int n) const {
        Arrays mat(n, Array(n, 0));
        const int target = n * n;
        int min_r = 0, min_c = 0, max_r = n - 1, max_c = n - 1, num = 1;
        while (true) {
            if (num > target) break;
            Array& lw_cols1 = mat[min_r]; 
            for (int c = min_c; c <= max_c; c++, num++) {
                lw_cols1[c] = num;
            }
            if (num > target) break;
            min_r ++;
            for (int r = min_r; r <= max_r; r++, num++) {
                mat[r][max_c] = num;
            }
            if (num > target) break;
            max_c --;
            Array& lw_cols2 = mat[max_r]; 
            for (int c = max_c; c >= min_c; c--, num++) {
                lw_cols2[c] = num;
            }
            if (num > target) break;
            max_r --;
            for (int r = max_r; r >= min_r; r--, num++) {
                mat[r][min_c] = num;
            }
            min_c ++;
        }
        return mat;
    }
};

int main(int argc, char** argv) {
    Solution sol;
    auto res = sol.generateMatrix(atoi(argv[1]));
    for (const auto& row: res) {
        for (int v: row) {
            printf("%4d, ", v);
        }
        printf("\n");
    }
    return 0;
}