#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/**
 * Bruteforce method: TLE
 * runtime: 
 * memory:  
 */
class Solution {
public:
    bool isPalindrome(const string& s, int start, int end) const noexcept {
        if (end - start <= 1) {
            return true; 
        }
        auto s_ptr = s.data() + start, e_ptr = s.data() + end - 1;
        for(;s_ptr < e_ptr; s_ptr++, e_ptr--) {
            if (*s_ptr != *e_ptr) {
                return false;
            }
        }
        return true;
    }
    
    int minCut(string s) const {
        int length = s.length();
        auto res = recursive_solve(s, 0, length);
        return res;
    }

    int recursive_solve(const string& s, int start, int end) const {
        if (end - start == 1) return 0;
        if (isPalindrome(s, start, end))
            return 0;
        int min_cut_num = 2000;
        for (int i = start + 1; i < end; i++) {
            if (i - start > 1 && !isPalindrome(s, start, i))
                continue;
            min_cut_num = std::min(recursive_solve(s, i, end), min_cut_num);
        }
        return min_cut_num + 1;
    }
};

int main(int argc, char** argv) {
    Solution sol;

    return 0;
}