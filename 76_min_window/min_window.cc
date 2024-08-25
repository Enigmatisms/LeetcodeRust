#include <vector>
#include <iostream>
#include <deque>
#include <unordered_map>

/**
 * 这道题思路不难... 就是要注意审题：t中重复的字符，在覆盖串中，对应的字符数量必须不少于 t重复字符的重复次数
 * 其实可以更简单，我相比官方解法的滑动窗口，应该是一次性可以跳过大块从未出现过的字符，但其实可以不用deque，这个太复杂了
 * runtime: 80.70%
 * memory:  5.01%       (双重哈希，太大了？)
 */

class Solution {
public:
    std::string minWindow(std::string s, std::string t) const {
        if (s.length() < t.length()) return std::string("");
        std::unordered_map<char, std::deque<int>> positions;
        std::unordered_map<char, size_t> mapping;
        for (char v: t) {
            if (mapping.count(v))
                mapping[v]++;
            else
                mapping[v] = 1;
        }
        int target_num = 0;
        for (auto& [ch, val]: mapping) {
            positions[ch] = std::deque<int>{};
            target_num += val;
        }
        char min_char = 0;
        int min_length = 100001, sp = 0, ep = 0;
        for (int i = 0; i < s.length(); i++) {
            char v = s[i];
            auto ref = mapping.find(v);
            if (ref != mapping.end()) {
                if (positions[v].size() != mapping[v])
                    target_num --;
                else
                    positions[v].pop_front();
                positions[v].push_back(i);
            } else {
                continue;
            }
            if (target_num == 0) {
                int mini_1st = i;
                for (auto& [ch, vals]: positions) {
                    if (vals.front() < mini_1st) {
                        mini_1st = vals.front();
                        min_char = ch;
                    }
                }
                int length = i + 1 - mini_1st;
                if (length < min_length) {
                    min_length = length;
                    sp = mini_1st;
                    ep = i + 1;
                }
                if (min_length == t.length())
                    return std::string(s.begin() + sp, s.begin() + ep);
                target_num = 1;
                positions[min_char].pop_front();
                printf("(%d / %lu) min char = %c\n", i, t.length(), min_char);
            }
        }
        if (sp == ep)
            return std::string("");
        return std::string(s.begin() + sp, s.begin() + ep);
    }

    // 重复字母不能少于原始t内对应字母的个数就很艹，下面是不考虑重复的解法，不需要额外存储
    std::string minWindowNoOverlap(std::string s, std::string t) const {
        if (s.length() < t.length()) return std::string("");
        std::unordered_map<char, int> mapping;
        for (char v: t) {
            mapping[v] = -1;
        }
        char min_char = 0;
        int mapping_size = mapping.size(), target_num = mapping_size;
        int min_length = 100001, sp = 0, ep = 0;
        for (int i = 0; i < s.length(); i++) {
            char v = s[i];
            auto ref = mapping.find(v);
            if (ref != mapping.end()) {
                if (mapping[v] == -1) {
                    target_num --;
                }
                mapping[v] = i;         // always keep the largest
            } else {
                continue;
            }
            if (target_num == 0) {
                int mini_1st = i;
                for (auto& [ch, val]: mapping) {
                    if (val < mini_1st) {
                        mini_1st = val;
                        min_char = ch;
                    }
                }
                int length = i + 1 - mini_1st;
                if (length < min_length) {
                    min_length = length;
                    sp = mini_1st;
                    ep = i + 1;
                }
                if (min_length == t.length())
                    return std::string(s.begin() + sp, s.begin() + ep);
                target_num = 1;
                mapping[min_char] = -1;
            }
        }
        if (sp == ep)
            return std::string("");
        return std::string(s.begin() + sp, s.begin() + ep);
    }
};

int main(int argc, char** argv) {    
    Solution sol;
    std::string s = "ADOBECODOEOBANC", t = argc > 1 ? std::string(argv[1]) : "OOO";
    auto res = sol.minWindow(s, t);
    std::cout << res << std::endl;
    return 0;
}