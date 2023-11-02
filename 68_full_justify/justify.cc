#include <vector>
#include <iostream>
#include <sstream>

/**
 * 这道题超级简单
 * runtime: 100.00%
 * memory:  22.21%
 */

class Solution {
public:
    std::vector<std::string> fullJustify(std::vector<std::string>& words, int maxWidth) {
        int ch_count = static_cast<int>(words.front().length()), all_word_num = static_cast<int>(words.size());
        int line_start = 0;
        std::vector<std::string> results;
        for (int i = 1; i < all_word_num; i++) {
            std::string word = words[i];
            int new_word_length = static_cast<int>(word.length());
            if (ch_count + new_word_length >= maxWidth) {       // plus 1
                int word_num = i - line_start;
                if (word_num == 1) {                            // only one word, fill the rest of the place in space
                    if (maxWidth - ch_count > 0)
                        results.emplace_back(words[line_start] + std::string(maxWidth - ch_count, ' '));
                    else                                        // or directly append the word to the back
                        results.emplace_back(words[line_start]);
                } else {
                    word_num --;
                    int total_space = maxWidth - ch_count + word_num;
                    int remaining_space = total_space % word_num, num_space = total_space / word_num;
                    std::stringstream ss;
                    ss << words[line_start];
                    for (int i = 0; i < word_num; i++) {
                        ss << std::string(num_space + int(remaining_space-- > 0), ' ');
                        ss << words[line_start + 1 + i];
                    }
                    results.emplace_back(ss.str());
                }
                // start a new line with the current word since it is not going to fit
                line_start = i;
                ch_count   = new_word_length;
            } else {
                ch_count  += new_word_length + 1;            // extra space
            }
        }
        std::stringstream ss;
        ss << words[line_start];
        for (int i = line_start + 1; i < all_word_num; i++) {
            std::string word = words[i];
            ss << ' ' << word;
        }
        int remaining_ch = maxWidth - ch_count;
        if (remaining_ch > 0) {
            ss << std::string(remaining_ch, ' ');
        }
        results.emplace_back(ss.str());
        return results;
    }
};

int main() {
    Solution sol;
    std::vector<std::string> inputs1{"This", "is", "an", "example", "of", "text", "justification."};
    std::vector<std::string> inputs2{"Science","is","what","we","understand","well","enough","to","explain","to","a","computer.","Art","is","everything","else","we","do"};
    std::vector<std::string> inputs3{"What","must","be","acknowledgment","shall","be"};
    std::vector<std::string> inputs4{"aaaaaaa", "b"};
    std::vector<std::string> inputs5{"aaaa"};
    std::vector<std::string> inputs6{"justification"};
    auto res1 = sol.fullJustify(inputs1, 16);
    auto res2 = sol.fullJustify(inputs2, 20);
    auto res3 = sol.fullJustify(inputs3, 16);
    auto res4 = sol.fullJustify(inputs4, 20);
    auto res5 = sol.fullJustify(inputs5, 6);
    auto res6 = sol.fullJustify(inputs6, 13);
    for (const auto& str: res1) {
        std::cout << str << "/" << std::endl;
    }
    std::cout << std::endl;
    for (const auto& str: res2) {
        std::cout << str << "/" << std::endl;
    }
    std::cout << std::endl;
    for (const auto& str: res3) {
        std::cout << str << "/" << std::endl;
    }
    std::cout << std::endl;
    for (const auto& str: res4) {
        std::cout << str << "/" << std::endl;
    }
    std::cout << std::endl;
    for (const auto& str: res5) {
        std::cout << str << "/" << std::endl;
    }
    std::cout << std::endl;
    for (const auto& str: res6) {
        std::cout << str << "/" << std::endl;
    }
    return 0;
}