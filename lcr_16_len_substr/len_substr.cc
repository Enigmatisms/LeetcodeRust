#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

/**
 * 不含重复字符的最长连续 str 
 * 感觉hash
 * runtime: 66.13%
 * memory:  39.96%
 */
class Solution {
public: 
    int lengthOfLongestSubstring(string s) {
        std::unordered_map<char, int> pos_map;
        int max_length = 0, size = s.length(), length = 0, last_ptr = 0;
        for (int i = 0; i < size; i++) {
            char c = s[i];
            auto it = pos_map.find(c);
            if (it == pos_map.end()) {          // 原来 pos_map 中没有 c
                length ++;
                pos_map[c] = i;
            } else {
                length = i - it->second;
                for (; last_ptr < it->second; last_ptr++)
                    pos_map.erase(s[last_ptr]);
                last_ptr ++;
                it->second = i;
            }
            max_length = std::max(max_length, length);
        }
        return max_length;
    }
};

int main(int argc, char** argv) {
    Solution sol;

    return 0;
}