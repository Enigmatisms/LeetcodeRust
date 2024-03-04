#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/**
 * 
 * runtime: 100.00%
 * memory:  30.08%
 */
class Solution {
public:
    string stringShift(string s, vector<vector<int>>& shift) {
        int shift_num = 0, slen = static_cast<int>(s.length());
        for (const std::vector<int>& op: shift) {
            if (op[0])
                shift_num += op[1];
            else
                shift_num -= op[1];
        }
        if (shift_num < 0) {
            shift_num = (-shift_num) % slen;
            shift_num = slen - shift_num;
        } else {
            shift_num %= slen;
        }
        return s.substr(slen - shift_num, shift_num) + s.substr(0, slen - shift_num);
    }
};

int main(int argc, char** argv) {
    Solution sol;

    return 0;
}