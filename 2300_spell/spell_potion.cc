#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/**
 * 可以的，中途出了点差错（需要排除一些极端情况）
 * runtime: 97.24%
 * memory:  98.55
 */
class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        std::sort(potions.begin(), potions.end());
        std::vector<int> results;
        results.reserve(spells.size());
        for (int spell: spells) {
            long long potion_target = (success + spell - 1) / spell;      // 向上取整
            if (potion_target > potions.back()) {
                results.push_back(0);
                continue;
            } else if (potion_target <= potions[0]) {
                results.push_back(potions.size());
                continue;
            }
            auto it = std::upper_bound(potions.begin(), potions.end(), potion_target);
            if (it > potions.begin()) {
                for (it = it - 1; it != potions.begin(); it--) {
                    if (*it != potion_target) {
                        ++ it; break;
                    }
                }
                if (it == potions.begin() && *it != potion_target) ++ it; 
            }
            results.push_back(potions.end() - it);
        }
        return results;
    }
};

int main(int argc, char** argv) {
    Solution sol;

    return 0;
}