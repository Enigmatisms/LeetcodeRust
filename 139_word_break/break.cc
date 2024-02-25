#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <unordered_map>
#include <unordered_set>

using namespace std;

/**
 * 这道题就是要用动态规划了... 拆分子问题
 * DP[i] 表示 s[0:i] (注意 这是 python 表示法，i无法取到) 是否可以被 wordDict 表示
 * 显然此问题可以转化为这样的子问题: j < i, DP[0:j] 是否为 true 且 s[j:i] 是否可以被表示
 * runtime: 65.09%
 * memory:  5.05% (为啥)
 */
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int slen = static_cast<int>(s.length() + 1);
        std::vector<bool> valid(slen, false);
        std::unordered_set<string> set;
        for (std::string s: wordDict)
            set.emplace(std::move(s));
        valid.front() = true;
        for (int i = 1; i <= slen; i++) {
            // whether s[0:i] can be represented by words in wordDict
            for (int j = 0; j < i; j++) {
                std::string sub_string = s.substr(j, i - j);
                if (valid[j] && set.count(sub_string)) {
                    valid[i] = true;
                    continue;
                }
            } 
        }
        return valid.back();
    }
};

int main(int argc, char** argv) {
    Solution sol;

    return 0;
}