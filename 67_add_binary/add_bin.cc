#include <string>
#include <sstream>
#include <iostream>

/**
 * 简单归简单。这种题目给你的启示就是: (1) 字符串加减记住是从字符串末尾开始，别傻乎乎地从开始进行。
 * (2) 双array循环问题可以用指针或者迭代器解决 
 * runtime: 100.00%
 * memory:  40.20%
 * 
 */

class Solution {
public:
    std::string addBinary(std::string a, std::string b) const {
        bool carry = false;
        std::stringstream ss;
        auto aptr = a.crbegin(), bptr = b.crbegin();
        for (; aptr != a.crend() && bptr != b.crend(); aptr++, bptr++) {
            char a_val = *aptr, b_val = *bptr;
            bool a_1 = (a_val != '0'), b_1 = (b_val != '0');
            if (a_1 || b_1) {           // not all 0
                bool ab_1 = a_1 && b_1;
                if (ab_1) {
                    ss << char(48 + int(carry));
                    carry = true;
                } else {
                    ss << char(48 + int(!carry));
                }
            } else {
                ss << char(48 + int(carry));
                carry = false;
            }
        }
        auto ptr = aptr, end_ptr = a.crend();
        if (bptr != b.crend()) {
            ptr = bptr;
            end_ptr = b.crend();
        }
        for (; ptr != end_ptr; ptr++) {
            char val = *ptr;
            if (carry) {
                bool val_1 = (val == '1');
                ss << char(49 - int(val_1));
                carry = val_1;
            } else {
                ss << val;
            }
        }
        if (carry)
            ss << '1';
        std::string result = ss.str();
        return std::string(result.rbegin(), result.rend());
    }
};


int main() {
    Solution sol;
    std::string a = "100", b = "110010";
    std::cout << sol.addBinary(a, b) << std::endl;
    return 0;
}