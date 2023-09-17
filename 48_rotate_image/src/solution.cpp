/**
执行用时：0 ms, 在所有 C++ 提交中击败了100.00%的用户
内存消耗：6.9 MB, 在所有 C++ 提交中击败了23.21%的用户
通过测试用例：21 / 21
 */

#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        uint8_t half = matrix.size() >> 1;
        for (uint8_t i = 0; i < half; i++) {
            recursive(matrix, i, matrix.size() - (i << 1) - 1);
        }
    }

    void recursive(vector<vector<int>>& matrix, uint8_t start, uint8_t length) {
        uint8_t full_len = start + length;
        for (uint8_t i = 0; i < length; i++) {
            uint8_t idx = start + i;
            uint8_t rev_idx = full_len - i;
            swap(matrix[start][idx], matrix[rev_idx][start]);
            swap(matrix[rev_idx][start], matrix[full_len][rev_idx]);
            swap(matrix[full_len][rev_idx], matrix[idx][full_len]);
        }
    }
};

int main() {
    vector<vector<int>> test = {{5,1,9,11},{2,4,8,10},{13,3,6,7},{15,14,12,16}};
    Solution s;
    s.rotate(test);
    for (const std::vector<int>& vec: test) {
        printf("[");
        for (const int& i: vec) {
            printf("%d, ", i);
        }
        printf("], ");
    }
    printf("\n");
    return 0;
}