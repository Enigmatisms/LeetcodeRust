#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <unordered_map>
#include <unordered_set>

using namespace std;

/**
 * runtime:
 * memory:
 */
class Solution {
public:
    std::string remove_ab(std::string str) {
        int a_cnt = 0;
        std::vector<char> chars;
        chars.reserve(str.size());
        for (size_t i = 0; i < str.size(); i++) {
            char c = str[i];
            if (c == 'a') {
                ++ a_cnt;
            } else if (c == 'b') {
                if (a_cnt > 0) {
                    -- a_cnt;
                } else {
                    chars.push_back(c);
                }
            } else {
                if (a_cnt) {
                    for (int k = 0; k < a_cnt; k++)
                        chars.push_back('a');
                }
                a_cnt = 0;
                chars.push_back(c);
            }
        }
        return std::string(chars.begin(), chars.end());
    }
};

int main(int argc, char** argv) {
    Solution sol;

    std::vector<string> tests = {"saabbd", "aacababaabsabd", "sabd", "ababababab", "abbbaacabc"};
    for (std::string s: tests) {
        std::cout << sol.remove_ab(s) << std::endl;
    }
    return 0;
}