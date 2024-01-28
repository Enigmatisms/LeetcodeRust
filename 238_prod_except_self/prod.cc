#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/**
 * 这题很简单
 * runtime: 99.63%
 * memory:  20.80%
 */
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        std::vector<int> nums_prod(nums.begin(), nums.end());
        const int length = nums.size();
        for (int i = 1; i <length; i++)
            nums_prod[i] *= nums_prod[i - 1];
        int back_prod = 1;
        for (int i = length - 1; i > 0; i--) {
            nums_prod[i] = nums_prod[i - 1] * back_prod;
            back_prod *= nums[i];
        }
        nums_prod[0] = back_prod;
        return nums_prod;
    }
};

int main(int argc, char** argv) {
    Solution sol;

    return 0;
}