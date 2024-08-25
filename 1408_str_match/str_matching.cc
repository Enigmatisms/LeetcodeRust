#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

/**
 * KMP 常看常新... 我真垃圾
 * 为什么这么垃圾？
 * runtime: 14.10%
 * memory:  11.11%
 */
class Solution {
public:
    // 100.00%, 37.18%
    vector<string> stringMatching(vector<string>& words) {
        int num_words = static_cast<int>(words.size());
        std::vector<std::string> results;
        for (int i = 0; i < num_words; i++) {
            const std::string& pattern = words[i];
            for (int j = 0; j < num_words; j++) {
                if (i == j) continue;
                if (words[j].find(pattern) != std::string::npos) {
                    results.push_back(pattern);
                    break;
                }
            }
        }
        return results;
    }

    // 自己写的 KMP 真的垃圾，不如 find, 虽然自己写的 KMP 可以求解所有位置
    vector<string> stringMatching_kmp(vector<string>& words) {
        int num_words = static_cast<int>(words.size());
        std::vector<std::string> results;
        for (int i = 0; i < num_words; i++) {
            const std::string& pattern = words[i];
            for (int j = 0; j < num_words; j++) {
                if (i == j) continue;
                if (strStr(words[j], pattern) >= 0) {
                    results.push_back(pattern);
                    break;
                }
            }
        }
        return results;
    }

    int strStr(const std::string& text, const std::string& pattern) const {
        const short hay_len = text.length(), ndl_len = pattern.length();
        if (hay_len < ndl_len) return -1;
        if (hay_len == 1)
            return text.front() == pattern.front() ? 0 : -1;
        std::vector<short> next(ndl_len, 1);
        const char* head_ptr = pattern.data(), *tail_ptr = pattern.data() + 1;
        short interval = 0;
        for (short i = 1; i < ndl_len; i++, tail_ptr++) {
            if (*tail_ptr == *head_ptr) {
                if (interval == 0)
                    interval = i;
                next[i] = interval;
                head_ptr ++;
            } else {
                head_ptr = pattern.data();
                interval = 0;
            }
        }
        head_ptr = text.data(), tail_ptr = pattern.data();
        const char* hay_end = text.data() + hay_len;
        for (short i = 0, j = 0; head_ptr < hay_end;) {
            if (head_ptr[i] == *tail_ptr) {
                j ++ ;
                if (j == ndl_len)
                    return head_ptr - text.data();
                tail_ptr ++ ;
                i ++ ;
            } else {
                tail_ptr = pattern.data();
                short step = (j > 0) ? next[j - 1] : 1;
                head_ptr += step;
                j = 0;
                i = 0;
            }
        }
        return -1;
    }
};

int main(int argc, char** argv) {
    Solution sol;

    return 0;
}