#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/**
 * 写得多少有点复杂了
 * runtime: 75.56%
 * memory:  45.97%
 */
class Solution {
public:
    string licenseKeyFormatting(string s, int k) {
        std::string temp, result;
        temp.reserve(s.size());
        for (char v: s) {
            if (v < '0') continue;
            temp.push_back(v - (v >= 'a' ? 32 : 0));
        }
        int num_valid = temp.size();
        if (num_valid == 0) return "";
        int init = num_valid % k, seps = (num_valid + k - 1) / k - 1;
        if (init == 0) init = k;
        result.reserve(num_valid + seps);
        for (int i = 0; i < init; i++)
            result.push_back(temp[i]);
        for (int i = 0, ptr = init; i < seps; i++) {
            result.push_back('-');
            for (int j = 0; j < k; j++, ptr++)
                result.push_back(temp[ptr]);
        }
        return result;
    }
};

int main(int argc, char** argv) {
    Solution sol;

    return 0;
}