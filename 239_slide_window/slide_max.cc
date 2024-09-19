#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

/**
 * 直接做出来了，但是很差，nlogn
 * 
 * runtime: 6.07%
 * memory:  4.98%
 */
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int len = nums.size();
        if (len == k) {
            return {*std::max_element(nums.begin(), nums.end())};
        }
        // 初始化 map
        std::map<int, int> hold;
        for (int i = 0; i < k; i++) {
            hold[nums[i]] ++;
        }
        std::vector<int> result;
        result.reserve(len - k);
        result.emplace_back(hold.rbegin()->first);
        for (int i = k; i < len; i++) {
            int to_remove = nums[i - k], to_add = nums[i];
            auto it = hold.find(to_remove);
            -- it->second;
            if (it->second == 0) {
                hold.erase(it);
            }
            hold[to_add] ++;
            result.emplace_back(hold.rbegin()->first);
        }
        return result;
    }
};

int main(int argc, char** argv) {
    Solution sol;

    return 0;
}