#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <unordered_map>
#include <unordered_set>

using namespace std;

/**
 * 思路并不难 终止操作需要非常小心
 * runtime: 76.19%
 * memory:  60.32%
 */
class Solution {
public:
    int longestDecomposition(string text) {
        int s_len = text.length(), sptr = 0, eptr = s_len - 1, result = 0;
        while (sptr < eptr) {
            if (text[sptr] == text[eptr]) {
                sptr ++;
                eptr --;
                result += 2;
                continue;
            }
            std::unordered_map<char, short> cnts1, cnts2;
            bool is_map_equal = false;
            do {
                if (sptr >= eptr) {
                    ++ result;
                    break;
                }
                ++ cnts1[text[sptr]];
                ++ cnts2[text[eptr]];
                ++ sptr;
                -- eptr;
                int rewind_len = 0;
                is_map_equal = map_equal(cnts1, cnts2, rewind_len);
                if (is_map_equal) {
                    for (int i = 0; i < rewind_len; i++) {
                        if (text[sptr - rewind_len + i] != text[eptr + i + 1]) {
                            is_map_equal = false;
                            break;
                        }
                    }
                    if (is_map_equal) result += 2;
                }
            } while (!is_map_equal);
        }
        return result;
    }

    bool map_equal(const std::unordered_map<char, short>& m1, const std::unordered_map<char, short>& m2, int& rewind_len) const {
        for (auto [key, cnt]: m1) {
            auto it = m2.find(key);
            if (it == m2.end()) return false;
            if (it->second != cnt) return false;
            rewind_len += cnt;
        }
        return true;
    }
};

int main(int argc, char** argv) {
    Solution sol;

    return 0;
}