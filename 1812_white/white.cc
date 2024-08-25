#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <unordered_map>
#include <unordered_set>

using namespace std;

/**
 * 简单到爆, 这是我做过最简单的题目, 30s 写出来
 * runtime: 100.00%
 * memory:  57.10%
 */
class Solution {
public:
    bool squareIsWhite(string coordinates) {
        return (coordinates[0] & 1) ^ (coordinates[1] & 1);
    }
};

int main(int argc, char** argv) {
    Solution sol;

    return 0;
}