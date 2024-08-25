#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/**
 * A thorough KMP algorithm review
 * KMP 实际上不仅可以计算最早出现的位置，也可以计算所有匹配位置
 * 这道题都能做这么久... 是真的傻了
 * runtime: 100.00%
 * memory:  31.69%
 * 可以看视频：https://www.youtube.com/watch?v=cH-5KcgUcOE 快速复习
 */
class Solution {
public:
    std::vector<int> string_match_multiple(const std::string& pattern, const std::string& text) {
        int pat_len = static_cast<int>(pattern.length()), txt_len = static_cast<int>(text.length());
        std::vector<int> nexts(pat_len, 0);     // next 数组

        // next 数组生成（自己也不断与自己匹配）
        for (int i = 1; i < pat_len; i++) {
            char cur_val = pattern[i];
            int ptr = nexts[i - 1];
            while (ptr > 0) {
                if (cur_val == pattern[ptr]) {
                    nexts[i] = ptr + 1;
                    break;
                }
                // pattern[i] != pattern[ptr] 
                ptr = nexts[ptr - 1];   
            }
            if (cur_val == pattern[ptr])
                nexts[i] = ptr + 1;
            else
                nexts[i] = 0;
        }
        for (int val: nexts) {
            printf("%d, ", val);
        }
        printf("\n");
        // 模式匹配
        std::vector<int> result_indices;
        int pat_i = 0;
        for (int i = 0; i < txt_len; i++, pat_i++) {
            if (pat_i >= pat_len) {
                result_indices.push_back(i - pat_len);
                pat_i = nexts[pat_i - 1];                
            }
            char cur_val = text[i];
            while (cur_val != pattern[pat_i]) {
                if (pat_i == 0) {
                    pat_i = -1;
                    break;
                }
                pat_i = nexts[pat_i - 1];
            }
        }
        if (pat_i >= pat_len)
            result_indices.push_back(txt_len - pat_len);
        return result_indices;
    }
};

int main(int argc, char** argv) {
    Solution sol;
    std::string pattern = "abcabcabcd";
    std::string text    = "abcabcabcdabcabcabcabcd";
    auto res = sol.string_match_multiple(pattern, text);
    for (int start: res) {
        std::cout << start << ": " << text.substr(start, pattern.length()) << std::endl;
    }
    return 0;
}