#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <unordered_map>
#include <unordered_set>

using namespace std;

/**
 * 简单是很简单了，但怎么用最小的 cost 去做？
 * runtime: 49.07%
 * memory:  6.21%
 */
class Solution {
public:
    int findMaxK(vector<int>& nums) {
        int max_elem = -1;
        std::unordered_set<int> reservior;
        reservior.reserve(nums.size());
        for (int num: nums) {
            if (reservior.count(-num)) {
                max_elem = std::max(max_elem, num > 0 ? num : -num);
            } else {
                reservior.emplace(num);
            }
        }
        return max_elem;
    }
};

int main(int argc, char** argv) {
    Solution sol;

    return 0;
}