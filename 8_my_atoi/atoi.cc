#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
/**
 * 这题真傻逼... 不过有限状态机就是很容易错
 * runtime: 100.00%
 * memory:  19.56%
 */
constexpr long MAX_INT = 2147483647;
class Solution {
public:
    int myAtoi(const string& s) const noexcept {
        if (s.length() == 0) return 0;
        bool positive = true, has_digit = false, non_digit = false;
        long result = 0;
        for (size_t i = 0; i < s.length(); i++) {
            for (; s[i] == ' '; i++) {
                if (has_digit) return positive ? result : -result;
                if (non_digit) return 0;
            }
            char cur_v = s[i];
            if (cur_v == '-') {           // multiple negative
                if (has_digit) return positive ? result : -result;
                if (non_digit) return 0;
                positive = false;
                non_digit = true;
            } else if (cur_v >= '0' && cur_v <= '9') {
                has_digit = true;
                result = 10 * result + static_cast<int>(cur_v - '0');
                if (result >= MAX_INT) {
                    if (positive) return MAX_INT;
                    if (result != MAX_INT) return - MAX_INT - 1;
                }
            } else if (cur_v == '+') {
                if (has_digit) return positive ? result : -result;
                if (non_digit) return 0;
                non_digit = true;
            } else {
                return positive ? result : -result;
            }
        }
        return positive ? result : -result;
    }
};

int main(int argc, char** argv) {
    Solution sol;

    return 0;
}