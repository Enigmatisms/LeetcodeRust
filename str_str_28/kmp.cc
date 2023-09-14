#include <string>
#include <vector>
#include <iostream>
/** KMP algorithm */
class Solution {
public:
    int strStr(const std::string& haystack, const std::string& needle) const {
        const short hay_len = haystack.length(), ndl_len = needle.length();
        if (hay_len < ndl_len) return -1;
        if (hay_len == 1)
            return haystack.front() == needle.front() ? 0 : -1;
        std::vector<short> next(ndl_len, 1);
        const char* head_ptr = needle.data(), *tail_ptr = needle.data() + 1;
        short interval = 0;
        for (short i = 1; i < ndl_len; i++, tail_ptr++) {
            if (*tail_ptr == *head_ptr) {
                if (interval == 0)
                    interval = i;
                next[i] = interval;
                head_ptr ++;
            } else {
                head_ptr = needle.data();
                interval = 0;
            }
        }
        head_ptr = haystack.data(), tail_ptr = needle.data();
        const char* hay_end = haystack.data() + hay_len;
        for (short i = 0, j = 0; head_ptr < hay_end;) {
            if (head_ptr[i] == *tail_ptr) {
                j ++ ;
                if (j == ndl_len)
                    return head_ptr - haystack.data();
                tail_ptr ++ ;
                i ++ ;
            } else {
                tail_ptr = needle.data();
                short step = (j > 0) ? next[j - 1] : 1;
                head_ptr += step;
                j = 0;
                i = 0;
            }
        }
        return -1;
    }
};

int main() {
    Solution sol;
    std::string a = "a";
    std::string b = "f";

    // std::string a = "ababababababc";
    // std::string b = "bababc";
    int idx = sol.strStr(a, b);
    printf("Index: %d\n", idx);
    return 0;
}