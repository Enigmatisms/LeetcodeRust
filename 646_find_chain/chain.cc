#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/**
 * 好像还可以有另一种
 * runtime: 68.36%
 * memory:  28.62%
 */
class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        int plen = static_cast<int>(pairs.size());
        std::sort(pairs.begin(), pairs.end(), 
            [](const std::vector<int>& v1, const std::vector<int>& v2) {
                return v1.front() < v2.front();
            }
        );
        std::vector<int> dp(plen);
        dp.front() = 1;
        for (int i = 1; i < plen; i++) {
            int cur_front = pairs[i].front(), max_val = 1;
            for (int j = 0; j < i; j++) {
                if (pairs[j].back() < cur_front) {
                    max_val = std::max(dp[j] + 1, max_val);
                }
            }
            dp[i] = max_val;
        }
        return *std::max_element(dp.begin(), dp.end());
    }
};

int main(int argc, char** argv) {
    Solution sol;

    return 0;
}