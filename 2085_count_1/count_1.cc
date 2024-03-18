#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

/**
 * 简单题... 但如果直接无脑做过去容易错。注意审题：两边都只有一个。
 * runtime: 99.76%
 * memory:  40.36%
 */
class Solution {
public:
    int countWords(vector<string>& words1, vector<string>& words2) {
        std::unordered_map<string, int> mapping;
        for (const auto& s: words1)
            mapping[s] -= 1;
        for (const auto& s: words2) {
            auto it = mapping.find(s);
            if (it == mapping.end()) continue;
            if (it->second < -1) continue;
            it->second ++;
        }
        int res = 0;
        for (const auto& [key, val]: mapping) {
            res += val == 0;
        }
        return res;
    }
};

int main(int argc, char** argv) {
    Solution sol;
    return 0;
}