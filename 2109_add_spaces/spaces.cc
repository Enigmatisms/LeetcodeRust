#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/**
 * 虽然秒杀 但是
 * 可以优化内存复杂度... 不要分割字符串，直接复制 char
 * runtime: 85.29%
 * memory:  5.88%
 */
class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) {
        int space_len = spaces.size();
        std::string res(s.begin(), s.begin() + spaces[0]);
        res.push_back(' ');
        for (int i = 1; i < space_len; i++) {
            std::string sub(s.begin() + spaces[i - 1], s.begin() + spaces[i]);
            sub.push_back(' ');
            res.append(std::move(sub));
        }
        res.append(std::string(s.begin() + spaces.back(), s.end()));
        return res;
    }
};

int main(int argc, char** argv) {
    Solution sol;

    return 0;
}