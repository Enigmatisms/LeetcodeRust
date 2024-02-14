#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/**
 * 
 * runtime: 81.37%
 * memory:  21.30%
 */
class Solution {
public:
    string reverseWords(string s) {
        bool count = false;
        std::vector<char> result;
        for (auto it = s.crbegin(); it != s.crend();) {
            for (; it != s.crend() && *it == ' '; it++) {
                if (count) {
                    result.emplace_back(' ');
                    count = false;
                }
                continue;
            }
            count = true;
            size_t start_size = result.size();
            for (; it != s.crend() && isalnum(*it); it++)
                result.emplace_back(*it);
            std::reverse(result.begin() + start_size, result.begin() + result.size());
        }
        if (result.back() == ' ') result.pop_back();
        return std::string(result.begin(), result.end());
    }
};

int main(int argc, char** argv) {
    Solution sol;

    return 0;
}