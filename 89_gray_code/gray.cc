#include <vector>
#include <bitset>
#include <iostream>

/**
 * 为什么这么慢
 * runtime:  29.33%
 * memory:   11.00%
 * 
*/

class Solution {
public:
    std::vector<int> grayCode(int n) const {
        return gray_recurse(n);
    }

    std::vector<int> gray_recurse(int step) const {
        if (step == 2) return {0, 1, 3, 2};
        else if (step == 1) return {0, 1};
        std::vector<int> lower_case = gray_recurse(step - 1);
        int initial_size = lower_case.size(), base = 1 << (step - 1);
        lower_case.resize(initial_size << 1);
        for (int i = 0; i < initial_size; i++)
            lower_case[initial_size + i] = lower_case[initial_size - i - 1] + base;
        return lower_case;
    }
};

void print_gray(const std::vector<int>& arr) {
    for (int v: arr) {
        std::bitset<8> bits(v);
        std::cout << bits << std::endl;
    }
}

int main() {
    Solution sol;
    for (int i = 1; i < 6; i++) {
        printf("Gray code for number: %d\n", i);
        print_gray(sol.grayCode(i));
    }
    return 0;
}