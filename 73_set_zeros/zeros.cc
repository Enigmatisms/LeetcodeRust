#include <vector>
#include <iostream>

/**
 * 本题的巧妙之处在于**空间复用**。很容易想到的一个方法是通过两个 std::vector<bool> 来记录每行及每列是否有 0
 * 不过这样的空间复杂度为 O(n + m)。不够好。实际上可以发现，矩阵的第一行第一列是可以用来记录一些信息的。
 * 假设某一列中存在0，则第一行对应元素一定为0，对行也是如此。故只需要两边遍历。
 * runtime: 97.11%
 * memory:  48.39%
 */

class Solution {
public:
    /**

     */
    void setZeroes(std::vector<std::vector<int>>& matrix) const {
        std::vector<int>& front = matrix.front();
        int num_rows = matrix.size(), num_cols = front.size();
        bool sr_has_0 = false, sc_has_0 = false;
        if (matrix[0][0] == 0) {
            sr_has_0 = true;
            sc_has_0 = true;
        } else {
            for (int i = 1; i < num_rows; i++) {
                if (matrix[i][0] == 0){
                    sc_has_0 = true;
                    break;
                }
            }
            for (int i = 1; i < num_cols; i++) {
                if (front[i] == 0){
                    sr_has_0 = true;
                    break;
                }
            }
        }
        for (int i = 1; i < num_rows; i++) {
            const std::vector<int>& row = matrix[i];
            for (int j = 1; j < num_cols; j++) {
                if (row[j] == 0) {
                    front[j] = 0;
                    matrix[i][0] = 0;
                }
            }
        }
        for (int j = 0; j < num_cols; j++) {
            if (front[j] == 0) {
                if (j == 0) continue;
                for (int i = 1; i < num_rows; i++) {
                    matrix[i][j] = 0;
                }
            } else if (sr_has_0) {
                front[j] = 0;
            }
        }
        for (int i = 0; i < num_rows; i++) {
            if (matrix[i][0] == 0) {
                std::vector<int>& row = matrix[i];
                for (int j = 1; j < num_cols; j++) {
                    row[j] = 0;
                }
            } else if (sc_has_0) {
                matrix[i][0] = 0;
            }
        }
    }
};

int main() {
    Solution sol;
    std::vector<std::vector<int>> M = {{1, 0}, {1, 1}};
    sol.setZeroes(M);
    for (const auto& arr: M) {
        for (int v: arr) {
            printf("%d, ", v);
        }
        printf("\n");
    }

    return 0;
}