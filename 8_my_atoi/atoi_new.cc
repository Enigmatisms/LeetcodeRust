#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <unordered_map>
#include <unordered_set>

using namespace std;

/**
 * 简洁多了
 * runtime: 100.00%
 * memory:  52.65%
 */
constexpr long long INT_MAX_1 = INT32_MAX + 1ll;
class Solution {
public:
    int myAtoi(const string& s) const noexcept {
        int length = static_cast<int>(s.length());
        long long digit = 0;
        bool should_digit = false, positive = true;
        for (int i = 0; i < length; i++) {
            char cur_val = s[i];
            if (cur_val == ' ') {
                if (should_digit) break;
            } else if (cur_val == '+' || cur_val == '-') {
                if (should_digit) break;
                should_digit = true;
                if (cur_val == '-') 
                    positive = false;
            } else if (cur_val >= '0' && cur_val <= '9') {
                should_digit = true;
                digit *= 10ll;
                digit += static_cast<long long>(cur_val - '0');
                if (digit >= INT_MAX_1) {
                    digit = INT_MAX_1;
                    break;
                }
            } else {
                break;
            }
        }
        if (positive)
            digit = std::min(2147483647ll, digit);
        return static_cast<int>(positive ? digit : -digit);
    }
};

int main(int argc, char** argv) {
    Solution sol;

    return 0;
}