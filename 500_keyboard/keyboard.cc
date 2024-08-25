#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <set>
#include <unordered_set>

using namespace std;

/**
 * set 速度好像还行, unordered_set 可能区别不大
 * 看复杂度的话 unordered_set 可能更胜一筹。但本题set的空间不大，所以查找效率仍然很高
 * runtime: 100%
 * memory:  31.97%
 */
class Solution {
private:
    std::vector<std::unordered_set<char>> kb_lines;
public:
    Solution() {
        kb_lines.push_back({'z', 'x', 'c', 'v', 'b', 'n', 'm'});
        kb_lines.push_back({'a', 's', 'd', 'f', 'g', 'h', 'j', 'k', 'l'});
        kb_lines.push_back({'q', 'w', 'e', 'r', 't', 'y', 'u', 'i', 'o', 'p'});
    }

    vector<string> findWords(vector<string>& words) {
        vector<string> result;
        for (string word: words) {
            char v_first = std::tolower(word[0]);
            int line = 0;
            if (!kb_lines[line].count(v_first)) {           // unroll, and no need to search the last set
                ++ line;
                if (!kb_lines[line].count(v_first)) {
                    ++ line;
                }
            }
            bool line_word = true;
            for (size_t i = 1; i < word.size(); i++) {
                if (kb_lines[line].count(std::tolower(word[i])) == 0) {
                    line_word = false;
                    break;
                }
            }
            if (line_word) result.push_back(word);
        }
        return result;
    }
};

int main(int argc, char** argv) {
    Solution sol;

    return 0;
}