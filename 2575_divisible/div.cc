#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <unordered_map>
#include <unordered_set>

using namespace std;

/**
 * 这题超简单
 * runtime: 92.00%
 * memory:  62.67%
 */
class Solution {
public:
    vector<int> divisibilityArray(string word, int m) {
        long long remaining = 0;
        std::vector<int> result;
        result.reserve(word.size());
        for (char v: word) {
            long digit = remaining * 10ll + static_cast<long long>(v - '0');
            remaining = digit % m;
            result.push_back(remaining == 0);
        }
        return result;
    }
};

int main(int argc, char** argv) {
    Solution sol;

    return 0;
}