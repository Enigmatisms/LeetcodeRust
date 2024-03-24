#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <unordered_map>
#include <unordered_set>

using namespace std;

/**
 * runtime: 100.00%
 * memory:  22.71%
 */
class Solution {
public:
    int compareVersion(string version1, string version2) {
        std::vector<int> ints1, ints2;
        convert_ints(ints1, version1);
        convert_ints(ints2, version2);
        int common_size = std::min(ints1.size(), ints2.size());
        for (int i = 0; i < common_size; i++) {
            int ver_int1 = ints1[i], ver_int2 = ints2[i];
            if (ver_int1 == ver_int2) continue;
            return (ver_int1 > ver_int2) * 2 - 1;
        }
        if (common_size < ints1.size()) {
            auto it = std::find_if(ints1.begin() + common_size, ints1.end(), [] (int v) {return v > 0;});
            if (it != ints1.end()) return 1;
        } else if (common_size < ints2.size()) {
            auto it = std::find_if(ints2.begin() + common_size, ints2.end(), [] (int v) {return v > 0;});
            if (it != ints2.end()) return -1;
        }
        return 0;
    }

    void convert_ints(std::vector<int>& ints, string& version) const {
        version.push_back('.');
        int s_len = version.length(), sptr = 0, eptr = 1;
        while (eptr < s_len) {
            if (version[eptr] == '.') {
                ints.push_back(atoi(version.substr(sptr, eptr - sptr).c_str()));
                sptr = eptr + 1;
                eptr = sptr + 1;
            } else {
                ++ eptr;
            }
        }

    }
};

int main(int argc, char** argv) {
    Solution sol;

    return 0;
}