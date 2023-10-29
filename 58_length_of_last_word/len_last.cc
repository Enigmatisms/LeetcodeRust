#include <string>

/**
 * 什么脑残题，这不是一分钟就能写出来？
 * runtime: 100.00%
 * memory:  46.61%
*/

class Solution {
public:
    int lengthOfLastWord(const std::string& s) const {
        int ptr = static_cast<int>(s.size()) - 1;
        int len = 0;
        for (; ptr >= 0; ptr --) {
            if (s[ptr] == ' ') {
                if (len > 0) {break;}
            } else {
                len++;
            }
        }
        return len;
    }
};

int main() {
    Solution sol;
    std::string test("Fxxk this shit. I want to test the last word length  ");
    printf("Length: %d\n", sol.lengthOfLastWord(test));
    return 0;
}