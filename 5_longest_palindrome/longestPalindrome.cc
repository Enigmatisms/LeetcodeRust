#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <unordered_map>
#include <unordered_set>

using namespace std;

/**
 * 这道题不适合用 DP 做。原因是不够直观。我很久之前的 （1.5年 +）做法就是中心扩展
 * 现在居然还要想那么久才能做出来...
 * runtime: 96.15%
 * memory:  85.03%
 */
class Solution {
public:
    string longestPalindrome(string s) {
        int slen = static_cast<int>(s.length()), res_s = 0, res_e = 0;
        for (int i = 0; i < slen; i++) {
            int sptr = i, eptr = i;
            expand_from_center(s, sptr, eptr, slen);
            if (eptr - sptr > res_e - res_s) {
                res_e = eptr;
                res_s = sptr;
            }
            sptr = i;
            eptr = i + 1;
            expand_from_center(s, sptr, eptr, slen);
            if (eptr - sptr > res_e - res_s) {
                res_e = eptr;
                res_s = sptr;
            }
        }
        return s.substr(res_s, res_e - res_s + 1);
    }

    void expand_from_center(const string& s, int& start, int& end, int slen) {
        int sptr = start, eptr = end;
        while (sptr >= 0 && eptr < slen && s[sptr] == s[eptr]) {
            sptr --;
            eptr ++;
        }
        start = sptr + 1;
        end   = eptr - 1;
    }
};

int main(int argc, char** argv) {
    Solution sol;
    sol.longestPalindrome("cbbd");
    return 0;
}