#include <iostream>
#include <numeric>
#include <vector>
using namespace std;

class Solution {
public:
    int pivotIndex(vector<int>& nums) const {
        int num_size = nums.size();
        if (num_size == 1) return 0;
        std::partial_sum(nums.begin(), nums.end(), nums.begin());
        int sum = nums.back();
        if (sum - nums[0] == 0) return 0;
        for (int i = 1; i < num_size; i++) {
            if (sum - nums[i] == nums[i - 1]) return i;
        }
        return -1;
    }
};

int main() {
    Solution sol;
    std::vector<std::vector<int>> tests = {
        {1, 7, 3, 6, 5, 6},
        {1, 2, 3},
        {2, 1, -1},
        {0, 0},
        {-1, 1, 2}
    };
    for (auto& vec: tests) {
        std::cout << sol.pivotIndex(vec) << std::endl;
    }
    return 0; 
}