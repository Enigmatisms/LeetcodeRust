#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/**
 * 
 * runtime: 80.99%
 * memory:  70.31%
 */
class Solution {
public:
    bool validPartition(vector<int>& nums) {
        int num_size = static_cast<int>(nums.size());
        std::vector<bool> dp(num_size, false);
        for (int i = 1; i < num_size; i++) {
            int current = nums[i];
            if (nums[i - 1] == current) {
                dp[i] = (i < 2) || dp[i - 2];
                if (dp[i]) continue;
            }
            if (i >= 2) {
                int prev_1 = nums[i - 1], prev_2 = nums[i - 2];
                if ((current == prev_1 && current == prev_2) || 
                    (current == prev_1 + 1 && current == prev_2 + 2)
                ) {
                    dp[i] = (i < 3) || dp[i - 3];
                }
            }
        }
        return dp.back();
    }
};

int main(int argc, char** argv) {
    Solution sol;
    std::vector<int> inputs = {4,4,4,5,6};
    std::cout << sol.validPartition(inputs) << std::endl;
    return 0;
}