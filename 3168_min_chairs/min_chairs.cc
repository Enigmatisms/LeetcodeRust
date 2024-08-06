#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

/**
 * 这是真正的简单题，一分钟AC
 * runtime: 100.00%
 * memory:  9.87%
 */
class Solution {
public:
    int minimumChairs(string s) {
        int max_chair = 0, chair = 0;
        for (char v: s) {
            if (v == 'E')
                ++ chair;
            else
                -- chair;
            max_chair = std::max(chair, max_chair);
        }
        return max_chair;
    }
};

int main(int argc, char** argv) {
    Solution sol;

    return 0;
}