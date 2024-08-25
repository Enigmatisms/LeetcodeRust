#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <set>

using namespace std;

/**
 * 原始实现太慢了，没过。最好的办法是排序 + 双指针
 * runtime: 
 * memory:  
 */
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        // O(n^2) 做法 有更好的吗？
        int num_size = nums.size();
        std::unordered_map<int, std::vector<int>> idx_map;
        for (int i = 0; i < nums.size(); i++) {
            int num = nums[i];
            idx_map[num].push_back(i);
        }
        std::unordered_map<int, std::set<int>> min_max;
        int cnt = 0;
        for (int i = 0; i < num_size - 2; i++) {
            int num_i = nums[i];
            for (int j = i + 1; j < num_size - 1; j++) {
                int num_j = nums[j], query = -(num_i + num_j);
                auto it = idx_map.find(query);
                if (it == idx_map.end()) continue;
                int idx = std::lower_bound(it->second.begin(), it->second.end(), j + 1) - it->second.begin();
                if (idx >= it->second.size()) continue;
                int mini = std::min(std::min(num_i, num_j), query),
                    maxi = std::max(std::max(num_i, num_j), query);
                min_max[mini].emplace(maxi);
                ++ cnt;
            }
        }
        std::vector<std::vector<int>> results;
        results.reserve(cnt);
        for (auto& [mini, all_maxi]: min_max) {
            for (int maxi: all_maxi) {
                results.push_back({mini, -(mini + maxi), maxi});
            }
        }
        return results;
    }
};

int main(int argc, char** argv) {
    Solution sol;

    return 0;
}