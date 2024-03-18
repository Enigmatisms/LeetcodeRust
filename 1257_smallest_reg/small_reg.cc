#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <unordered_map>
#include <unordered_set>

using namespace std;

/**
 * 妈的这道题就是tm的扯淡
 * 这道题描述极其不清楚，如果出现了这种情况，我的方法就无法应对了
 [["North America","New York","Boston"],["United States","New York","Boston"],["North America","United States","Canada"]]
 * 也即，new york 和 boston 同时出现在 north am 以及 us 中，这俩是相互包含的，这种情况非常难处理
 * 解答也是错的 顶级傻逼
 * 
 * runtime: 66.67%
 * memory:  58.33%
 */
class Solution {
public:
    string findSmallestRegion(vector<vector<string>>& regions, string region1, string region2) {
        std::unordered_map<string, string> father;
        for (const auto& vec: regions) {
            auto fa = vec[0];
            for (size_t i = 1; i < vec.size(); i++) {
                father[vec[i]] = fa;
            }
        }
        std::unordered_set<string> traversed = {region1};
        while (true) {
            auto fa_it = father.find(region1);
            if (fa_it == father.end()) break;
            region1 = fa_it->second;
            traversed.emplace(region1);
        }

        while (true) {
            if (traversed.count(region2)) break;
            auto fa_it = father.find(region2);
            region2 = fa_it->second;
        }
        return region2;
    }
};


int main(int argc, char** argv) {
    Solution sol;

    return 0;
}