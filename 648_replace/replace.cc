#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <sstream>
#include <unordered_map>
#include <unordered_set>

using namespace std;

/**
 * 这道题... 真的很暴力
 * runtime: 18.80%
 * memory:  11.16%
 */
class Solution {
public:
    string replaceWords(vector<string>& dictionary, string sentence) {
        sentence.push_back(' ');
        std::unordered_set<string> dict(dictionary.begin(), dictionary.end());
        int sptr = 0, eptr = 1, slen = sentence.size();
        std::vector<std::string> subs;
        while (eptr < slen) {
            if (sentence[eptr] == ' ') {
                subs.push_back(sentence.substr(sptr, eptr - sptr));
                sptr = eptr + 1;
                eptr = sptr + 1;
                continue;
            }
            std::string sub = sentence.substr(sptr, eptr - sptr);
            if (dict.count(sub)) {
                subs.push_back(sub);
                while (eptr < slen && sentence[eptr] != ' ')
                    ++ eptr;
                sptr = eptr + 1;
                eptr = sptr + 1;
            } else {
                ++ eptr;
            }
        }
        int num_subs = subs.size();
        std::string ans;
        for (int i = 0; i < num_subs - 1; i++) {
            ans.append(subs[i]);
            ans.push_back(' ');
        }
        ans.append(subs.back());
        return ans;
    }
};

int main(int argc, char** argv) {
    Solution sol;

    return 0;
}