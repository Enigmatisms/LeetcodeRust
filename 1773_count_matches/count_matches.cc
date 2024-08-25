#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <unordered_map>
#include <unordered_set>

using namespace std;

/**
 * 什么30s就能做出来的题目...
 * runtime: 95.24%
 * memory:  71.00%
 */
class Solution {
public:
    int countMatches(vector<vector<string>>& items, string ruleKey, string ruleValue) {
        int cnt = 0;
        if (ruleKey == "type") {
            for (const auto& item: items) {
                cnt += ruleValue == item[0];
            }
        } else if (ruleKey == "color") {
            for (const auto& item: items) {
                cnt += ruleValue == item[1];
            }
        } else {
            for (const auto& item: items) {
                cnt += ruleValue == item[2];
            }
        }
        return cnt;
    }
};

int main(int argc, char** argv) {
    Solution sol;

    return 0;
}