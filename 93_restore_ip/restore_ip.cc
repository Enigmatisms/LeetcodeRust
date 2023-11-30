#include <iostream>
#include <vector>

class Solution {
public:
    std::vector<std::string> restoreIpAddresses(std::string s) {

    }

    void restore_recursive(
        const std::string& s, std::vector<std::string>& interm, 
        std::vector<std::string>& results, int slen, int dot_left, int start_index
    ) {
        if (slen < 4) return;                      // being too short
        int remaining = slen - start_index;
        if (remaining <= dot_left) return;         // remaining too short
        if (remaining > dot_left * 3 + 3) return;  // remaining too long
        char start_c = s[start_index];
        if (start_c == '0') {
            if (remaining > (dot_left * 3 + 1)) return;
            if (dot_left == 0) {

            }
            restore_recursive(s, results, interm, slen, dot_left - 1, start_index + 1);
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
                    restore_recursive(s, interm, results, slen, dot_left - 1, start_index + i);
                }
            } else {

            }
        }
    }
};

int main() {

}