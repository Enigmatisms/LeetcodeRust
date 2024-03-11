#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <unordered_map>
#include <unordered_set>

using namespace std;

/**
 * runtime: 100.00%
 * memory:  29.75%
 */
class Solution {
public:
    string capitalizeTitle(string title) {
        title.push_back(' ');
        int slen = title.size(), sptr = 0, eptr = 0;
        for (; eptr < slen; eptr++) {
            char curc = title[eptr];
            if (curc == ' ') {
                char& start = title[sptr];
                if (eptr - sptr >= 3) {
                    if (start >= 'a')
                        start -= 32;
                } else {
                    if (start <= 'Z')
                        start += 32;
                }
                for (sptr = sptr + 1; sptr < eptr; sptr++) {
                    char& v = title[sptr];
                    if (v <= 'Z')
                        v += 32;
                }
                ++sptr;
                ++eptr;
            }
        }
        title.pop_back();
        return title;
    }
};

int main(int argc, char** argv) {
    Solution sol;

    return 0;
}