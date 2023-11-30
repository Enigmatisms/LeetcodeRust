#include <iostream>
#include <vector>
#include <sstream>

/**
 * 这道题不难... 但我为什么能写这么长我是不懂的。
 * 好吧，官方题解也比较长
 * runtime: 100%
 * memory:  40.39%
 * 
*/

class Solution {
public:
    std::vector<std::string> restoreIpAddresses(std::string s) {
        std::vector<std::string> results, interms;
        restore_recursive(s, interms, results, s.length(), 3, 0);
        return results;
    }

    inline std::string accumulate(const std::vector<std::string>& interms, std::string tail) const {
        std::stringstream ss;
        for (auto v: interms) ss << v << ".";
        ss << tail;
        return ss.str();
    }

    void restore_recursive(
        const std::string& s, std::vector<std::string>& interm, 
        std::vector<std::string>& results, int slen, int dot_left, int start_index
    ) {
        if (slen < 4 || slen > 12) return;                      // being too short
        int remaining = slen - start_index;
        if (remaining <= dot_left) return;         // remaining too short
        if (remaining > dot_left * 3 + 3) return;  // remaining too long
        char start_c = s[start_index];
        if (start_c == '0') {
            if (remaining > (dot_left * 3 + 1)) return;
            if (dot_left == 0) {   // .0x(x) will not be allowed, .0 will be allowed
                if (remaining > 1) return;
                results.push_back(accumulate(interm, s.substr(start_index, remaining)));
                return;
            }
            interm.push_back("0");
            restore_recursive(s, interm, results, slen, dot_left - 1, start_index + 1);
            interm.pop_back();
            return;
        } else {
            if (dot_left > 0) {
                for (int i = 1; i <= 3; i++) {
                    if (start_index + i >= slen) continue;
                    if (i == 3) {
                        if (start_c > '2') continue;
                        else if (start_c == '2') {
                            char c2 = s[start_index + 1], c3 = s[start_index + 2];
                            if (c2 > '5' || (c2 == '5' && c3 > '5')) continue;
                        }
                    }
                    interm.push_back(s.substr(start_index, i));
                    restore_recursive(s, interm, results, slen, dot_left - 1, start_index + i);
                    interm.pop_back();
                }
            } else {
                if (remaining == 3) {
                    if (start_c > '2') return;
                    else if (start_c == '2') {
                        char c2 = s[start_index + 1], c3 = s[start_index + 2];
                        if (c2 > '5' || (c2 == '5' && c3 > '5')) return;
                    }
                }
                results.push_back(accumulate(interm, s.substr(start_index, remaining)));
            }
        }
    }
};

int main() {
    Solution sol;
    std::vector<std::string> tests{"25525511135", "0000", "101023", "111111111", "123123123", "987", "00000", "12345678901234", "987654212"};
    for (std::string str: tests) {
        auto results = sol.restoreIpAddresses(str);
        for (std::string res: results) {
            std::cout << res << ", ";
        }
        std::cout << results.size() << std::endl;
    }
    return 0;
}