#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <unordered_map>
#include <unordered_set>

using namespace std;

int rand7() {
    return (rand() % 7) + 1;
}

/**
 * 这题看起来很有意思啊 想到一种很有意思的解法
 * 几何分布： 49 / 40 * 2 次 为期望
 * runtime: 76.69%
 * memory:  56.18%
 */
class Solution {
public:
    int rand10() {
        int result = 0;
        do {
            int row = rand7(), col = rand7();
            int idx = (row - 1) * 7 + col;
            if (idx > 40) continue;
            result = (idx + 3) / 4;  
            break;
        } while (true);
        return result;
    }
};

int main(int argc, char** argv) {
    srand(0);
    Solution sol;
    std::array<int, 10> cnts = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    for (int i = 0; i < 500000; i++) {
        ++ cnts[sol.rand10() - 1];
    }
    for (int i = 0; i < 10; i++) {
        printf("ratio (%d) = %f\n", i + 1, float(cnts[i]) / 500000.f);
    }
    return 0;
}