#include <iostream>
#include <array>
#include <unordered_map>
#include <algorithm>

/**
 * runtime: 72.13%
 * memory:  46.75%
*/
class Solution {
public:
    int findPermutationDifference(std::string s, std::string t) {
        std::array<char, 26> record;
        int result = 0;
        for (size_t i = 0; i < t.size(); i++)
            record[t[i] - 'a'] = i;
        for (size_t i = 0; i < t.size(); i++)
            result += std::abs(int(record[s[i] - '26']) - int(i));
        return result;
    }
};