#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/**
 * 脑残题，做不出来就remake吧，这不秒杀？
 * runtime: 100.00%
 * memory:  65.36%
 */
class Solution {
public:
    string maximumOddBinaryNumber(string s) {
        int slen = s.size(), num_1 = 0;
        for (int i = 0; i < slen - 1; i++) {
            if (s[i] == '1') {
                s[i] = '0';
                ++ num_1;
            }
        } 
        bool last_pos_1 = !num_1 || s.back() == '1';
        if (last_pos_1) {
            for (int i = 0; i < num_1; i++)
                s[i] = '1';
        } else {
            for (int i = 0; i < num_1 - 1; i++)
                s[i] = '1';
            s.back() = '1';
        }
        return s;
    }
};

int main(int argc, char** argv) {
    Solution sol;

    return 0;
}