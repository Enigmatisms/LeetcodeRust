#include <iostream>
#include <vector>
/**
 * Speed: 100.00%
 * Memory: 32.12%
*/

class Solution {
public:
    /**
     * 这道题本身是很简单的，但是我本人的一个特点就是细节处理很差: break 的判定应该都有的，这里写得很乱。搞了很久才搞通。
     * 最佳思路很容易想出来，确实就是这样，但是我个人花了30min才跑对... 一直因为边界问题爆炸... 真的傻逼
     * 所以，启发就是，逻辑之前的联系性需要格外注意
    */
    std::vector<int> spiralOrder(const std::vector<std::vector<int>>& matrix) const {
        int max_r = static_cast<int>(matrix.size()), max_c = static_cast<int>(matrix.front().size());
        int start_r = 0, start_c = 0;
        std::vector<int> results;
        results.reserve(max_r * max_c);
        while (true) {
            const std::vector<int>& row_vals1 = matrix[start_r];
            for (int i = start_c; i < max_c; i++) {
                results.push_back(row_vals1[i]);
            }
            start_r++;
            if (start_r == max_r) break;           // 提交后的注解: 由于 max_r - 1 开始，所以折柳就要退出

            max_c--;
            for (int i = start_r; i < max_r; i++) {
                results.push_back(matrix[i][max_c]);
            }
            if (max_c == start_c) break;           // 存在单列的情况
            const std::vector<int>& row_vals2 = matrix[max_r - 1];
            for (int i = max_c - 1; i >= start_c; i--) {
                results.push_back(row_vals2[i]);
            }
            max_r--;
            if (start_r == max_r) break;            // 看下面的逻辑,max_r - 1小于 start_r 了显然没用，直接退
            for (int i = max_r - 1; i >= start_r; i--) {
                results.push_back(matrix[i][start_c]);
            }
            start_c++;                              // 看回到一开始的逻辑
            if (max_c == start_c) break;
        }
        return results;
    }
};

int main() {
    Solution sol;
    std::vector<std::vector<int>> first_test;
    int cnt = 1;
    for (int i = 0; i < 4; i++) {
        std::vector<int> vals;
        for (int j = 0; j < 3; j++, cnt++) {
            vals.push_back(cnt);
        }
        first_test.push_back(vals);
    }
    auto res = sol.spiralOrder(first_test);
    for (const int& v: res) {
        printf("%d, ", v);
    }
    printf("\n");
    return 0;
}