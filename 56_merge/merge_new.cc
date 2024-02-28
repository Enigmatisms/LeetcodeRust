#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/**
 * 一遍过，五分钟写出来... 时隔差不多半年，早记不住思路
 * runtime: 80.07%
 * memory:  19.54%
 */
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> results;
        std::sort(intervals.begin(), intervals.end(), 
            [](const std::vector<int>& v1, const std::vector<int>& v2) {
                return v1.front() < v2.front();
            }
        );
        int range_s = intervals[0].front(), range_e = intervals[0].back();
        for (size_t i = 1; i < intervals.size(); i++) {
            int cur_s = intervals[i].front(), cur_e = intervals[i].back(); 
            if (cur_s <= range_e)
                range_e = std::max(range_e, cur_e);
            else {
                results.push_back({range_s, range_e});
                range_s = cur_s;
                range_e = cur_e;
            }
        }
        results.push_back({range_s, range_e});
        return results;
    }
};

int main(int argc, char** argv) {
    Solution sol;

    return 0;
}