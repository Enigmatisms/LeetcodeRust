#include <vector>
#include <iostream>
#include <algorithm>

/**
 * runtime: 100.00% 二分查找而已，没有任何问题
 * memory:   11.36%
 */

class Solution {
public:
using Array  = std::vector<int>;
using Matrix = std::vector<Array>;
public:
    bool searchMatrix(Matrix& matrix, int target) const {
        // special case, matrix has only one row
        int sp = 0, ep = static_cast<int>(matrix.size());
        int mp = (sp + ep) >> 1;
        while (ep - sp > 1) {
            int mp_front = matrix[mp].front();
            if (mp_front > target) {
                ep = mp;
            } else if (mp_front < target) {
                sp = mp;
            } else {
                return true;
            }
            mp = (sp + ep) >> 1;
        }
        // printf("Final row: %d\n", sp);
        if (matrix[sp].back() < target) return false;
        return std::binary_search(matrix[sp].begin(), matrix[sp].end(), target);
    }
};

int main(int argc, char** argv) {
    Solution sol;
    Solution::Matrix mat{{1,3,5,7},{10,11,16,20},{23,30,34,60}, {61, 70, 80, 90}};
    std::vector<int> tests{3, 13, 20, 21, -1, 34, 40, 59, 60, 61, 65, 80, 91};
    for (int v: tests) {
        printf("%d in mat? %d\n", v, int(sol.searchMatrix(mat, v)));
    }
    return 0;
}