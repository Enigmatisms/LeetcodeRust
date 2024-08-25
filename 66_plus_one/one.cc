#include <vector>
#include <iostream>

/**
 * runtime: 100.00%
 * memory:   41.96%
*/

class Solution {
public:
    std::vector<int> plusOne(std::vector<int>& digits) const {
        int carry = false;
        digits.back() += 1;
        if (digits.back() > 9) {
            carry = true;
            digits.back() = 0;
        } else {
            return digits;
        }
        for (auto rit = digits.rbegin() + 1; rit != digits.rend(); rit++) {
            *rit += 1;
            if (*rit <= 9) {
                carry = false;
                break;
            } 
            *rit = 0;
        }
        if (carry) {
            std::vector<int> result(digits.size() + 1, 1);
            for (size_t i = 0; i < digits.size(); i++) {
                result[i + 1] = digits[i];
            }
            return result;
        }
        return digits;
    }
};

int main() {
    Solution sol;
    std::vector<int> test1{4, 3, 3, 2};
    std::vector<int> test2{9, 9, 9, 9};
    std::vector<int> test3{9, 2, 9, 9};
    auto v1 = sol.plusOne(test1);
    auto v2 = sol.plusOne(test2);
    auto v3 = sol.plusOne(test3);
    for (float v: v1) {
        std::cout << v;
    }
    std::cout << std::endl;

    for (float v: v2) {
        std::cout << v;
    }
    std::cout << std::endl;

    for (float v: v3) {
        std::cout << v;
    }
    std::cout << std::endl;
    return 0;
}