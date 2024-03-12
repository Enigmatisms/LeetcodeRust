#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <unordered_map>
#include <unordered_set>

using namespace std;

/**
 * 首先找出有多少对好友不能交流
 * runtime: 45.10%
 * memory:  25.49%
 */
class Solution {
public:
    int minimumTeachings(int n, vector<vector<int>>& languages, vector<vector<int>>& friendships) {
        std::vector<std::unordered_set<int>> langs;
        langs.reserve(languages.size());
        for (const std::vector<int>& lang: languages)
            langs.emplace_back(lang.begin(), lang.end());
        std::vector<short> lang_cnt(n, 0);
        std::unordered_set<short> no_comm;
        for (const std::vector<int>& fship: friendships) {
            int f1 = fship[0] - 1, f2 = fship[1] - 1;
            if (langs[f1].size() > langs[f2].size()) 
                std::swap(f1, f2);
            const std::unordered_set<int>& tar = langs[f2];
            bool can_comm = false;
            for (int lang: langs[f1]) {
                if (tar.count(lang)) {
                    can_comm = true;
                    break;
                }
            }
            if (!can_comm) {
                if (no_comm.count(f1) == 0) {
                    no_comm.emplace(f1);
                    for (int lang: languages[f1])
                        ++ lang_cnt[lang - 1];
                }
                if (no_comm.count(f2) == 0) {
                    no_comm.emplace(f2);
                    for (int lang: languages[f2])
                        ++ lang_cnt[lang - 1];
                }
            }
        }
        if (!no_comm.size()) return 0;
        return no_comm.size() - *std::max_element(lang_cnt.begin(), lang_cnt.end());
    }
};

int main(int argc, char** argv) {
    Solution sol;

    return 0;
}