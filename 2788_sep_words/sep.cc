#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/**
 * C++ 做这个就没有 python 那么简单了
 * 我还错了两次...
 * runtime: 81.19%
 * memory:  63.62%
 */
class Solution {
public:
    vector<string> splitWordsBySeparator(vector<string>& words, char separator) {
        std::vector<string> result;
        for (auto& word: words) {
            if (word.back() != separator)
                word.push_back(separator);
            int wlen = word.size();
            for (int ep = 0, sp = 0; ep < wlen; ep++) {
                char v = word[ep];
                if (v == separator) {
                    if (ep - sp && word[sp] != separator)
                        result.push_back(word.substr(sp, ep - sp));
                    sp = ep + 1;
                    while (sp < wlen && word[sp] == separator)
                        sp ++;
                    ep = sp;
                }
            }
        }
        return result;
    }
};

int main(int argc, char** argv) {
    Solution sol;

    return 0;
}