#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/**
 * C++ API 的妙用（我还不知道呢）
 * runtime: 49.49% (mine) / 100.00% (API)
 * memory:  18.61% (mine) / 23.57%  (API)
 */
class Solution {
public:
    bool isPalindrome(const string& s) const noexcept {
        int length = s.length();
        if (length <= 1) return true;
        auto s_ptr = s.data(), e_ptr = s_ptr + length - 1;
        for(;; s_ptr++, e_ptr--) {
            while (s_ptr < e_ptr && !isalnum(*s_ptr))
                s_ptr++;
            while (s_ptr < e_ptr && !isalnum(*e_ptr))
                e_ptr--;
            if (s_ptr >= e_ptr) break;
            if (tolower(*s_ptr) != tolower(*e_ptr)) return false;
        }
        return true;
    }

    bool isPalindromeMine(string s) {
        int length = s.length();
        if (length <= 1) return true;
        auto s_ptr = s.data(), e_ptr = s_ptr + length - 1;
        for(;s_ptr < e_ptr; s_ptr++, e_ptr--) {
            while (s_ptr < e_ptr && (*s_ptr < 'a' || *s_ptr > 'z')) {
                if (*s_ptr >= 'A' && *s_ptr <= 'Z') {
                    *s_ptr += 32;
                    break;
                } else if (*s_ptr >= '0' && *s_ptr <= '9') break;
                s_ptr++;
            }
            while (s_ptr < e_ptr && (*e_ptr < 'a' || *e_ptr > 'z')) {
                if (*e_ptr >= 'A' && *e_ptr <= 'Z') {
                    *e_ptr += 32;
                    break;
                } else if (*e_ptr >= '0' && *e_ptr <= '9') break;
                e_ptr--;
            }
            if (s_ptr >= e_ptr) break;
            if (*s_ptr != *e_ptr) return false;
        }
        return true;
    }
};

int main(int argc, char** argv) {
    Solution sol;

    return 0;
}