#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

/**
 * runtime: 100.00%
 * memory:  29.01%
*/
class Solution {
public:
    int longestPalindrome(std::string s) {
        // 奇数找最长的放中间（不对，可以扔一个成为偶数），偶数全加起来
        std::unordered_map<char, short> cnts;
        for (char v: s) {
            cnts[v] ++;
        }
        bool has_odd = false;
        short length = 0;
        for (auto [_, cnt]: cnts) {
            if (cnt & 1) {
                has_odd = true;
                length += cnt - 1;
            } else {
                length += cnt;
            }
        }
        return length + has_odd;
    }
};