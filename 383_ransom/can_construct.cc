#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <unordered_map>
#include <unordered_set>

using namespace std;

/**
 * runtime: 95.66%
 * memory:  62.75%
 */
class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        std::array<int, 26> maga_cnts;
        maga_cnts.fill(0);
        for (char c: magazine)
            ++ maga_cnts[c - 'a'];
        
        for (char c: ransomNote) {
            int& cnt = maga_cnts[c - 'a'];
            if (cnt) {
                --cnt;
            } else {
                return false;
            }
        }
        return true;
    }
};

int main(int argc, char** argv) {
    Solution sol;

    return 0;
}