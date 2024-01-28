#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/**
 * 
 * runtime: 100.00%
 * memory:  11.57%
 */
class Solution {
public:
    vector<int> getRow(int rowIndex) const {
        if (rowIndex <= 2) {
            switch (rowIndex) {
                case 0: return {1};
                case 1: return {1, 1};
                case 2: return {1, 2, 1};
            }
        }
        std::vector<int> result = {1, 3, 3, 1};
        result.resize(rowIndex + 1, 0);
        bool digit_front = true;
        for (int i = 3; i < rowIndex; i++, digit_front = !digit_front) {
            if (digit_front) {
                for (int j = i; j >= 0; j--)
                    result[rowIndex + j - i] = result[j] + result[j + 1];
                result[rowIndex - i - 1] = result[0];
                for (int j = rowIndex - i - 2; j >= 0; j--)
                    result[j] = 0;
            } else {
                for (int j = 0; j <= i; j++)
                    result[j] = result[rowIndex - i + j] + result[rowIndex - i + j - 1];
                result[i + 1] = result[rowIndex];
                for (int j = i + 2; j <= rowIndex; j++)
                    result[j] = 0;
            }
        }
        return result;
    }
};

int main(int argc, char** argv) {
    Solution sol;
    auto res = sol.getRow(atoi(argv[1]));
    for (int v: res) {
        printf("%d, ", v);
    }
    printf("\n");
    return 0;
}