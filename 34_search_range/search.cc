#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <unordered_map>
#include <unordered_set>

using namespace std;

/**
 * runtime: 92.72%
 * memory:  99.93%
 */
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int lb = std::lower_bound(nums.begin(), nums.end(), target) - nums.begin(),
            ub = std::upper_bound(nums.begin() + lb, nums.end(), target) - nums.begin();
        if (lb == ub) return {-1, -1};
        return {lb, ub - 1};
    }
};

int main(int argc, char** argv) {
    Solution sol;

    return 0;
}