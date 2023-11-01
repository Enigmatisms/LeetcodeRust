#include <vector>
#include <iostream>

/**
 * 所以你现在知道了，你的弱项在于下标处理（涉及到下标以及需要存储，可能覆盖的逻辑）
 * 这TM算困难题？
 * runtime: 100.00%
 * memory:  52.42%
 */

class Solution {
public:
    bool isNumber(std::string s) const {
        int len_s = static_cast<int>(s.length());
        bool can_have_sign = true, front_complete = false, dot_present = false, have_digit = false, e_resolved = true;
        for (int i = 0; i < len_s; i++) {
            char val = s[i];
            if ((val == '-' || val == '+')) {
                if (can_have_sign == false) return false;       // double sign case
                can_have_sign = false;
            } else if (val > 57) {
                if (front_complete == true) return false;       // ee case
                if (!have_digit)
                    return false;      // .e case
                if (val == 'e' || val == 'E') {
                    front_complete = true;
                    can_have_sign = true;
                    e_resolved = false;
                } else {                                        // other letter case
                    return false;
                }
            } else if (val == '.') {
                if (dot_present || front_complete) {            // multiple . or e*. case
                    return false;
                }
                dot_present = true;
            } else {
                have_digit = true;
                if (e_resolved == false)
                    e_resolved = true;
            }
            if (e_resolved) {
                can_have_sign = false;
            }
        }
        return have_digit && e_resolved;
    }
};

int main() {
    Solution sol;
    std::vector<std::string> positives{"2", "0089", "-0.1", "+3.14", "4.", "-.9", "2e10", "-90E3", "3e+7", "+6e-1", "53.5e93", "-123.456e789"};
    std::vector<std::string> negatives{"abc", "1a", "1e", "e3", "99e2.5", "--6", "-+3", "95a54e53"};
    for (const auto& str: positives) {
        std::cout << sol.isNumber(str) << ",";
    }
    std::cout << std::endl;
    for (const auto& str: negatives) {
        std::cout << sol.isNumber(str) << ",";
    }
    std::cout << std::endl;
    return 0;
}