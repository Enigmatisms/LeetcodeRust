#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

/**
 * 哈希表记录，并跳过一些不必要的搜索
 * runtime: 82.13%
 * memory:  29.49%
 */
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        std::unordered_map<int, bool> map;
        for (int num: nums)
            map[num] = false;
        int max_length = 0;
        for (auto it = map.begin(); it != map.end(); it ++) {
            if (it->second) continue;       // accessed
            if (map.count(it->first - 1)) continue;
            int length = 0;
            for (auto new_it = it; new_it != map.end() ; length ++) {
                new_it->second = true;
                new_it = map.find(new_it->first + 1);
            }
            max_length = std::max(max_length, length);
        }        
        return max_length;
    }
};

int main(int argc, char** argv) {
    Solution sol;

    return 0;
}