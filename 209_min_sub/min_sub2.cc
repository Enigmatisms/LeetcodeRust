#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/**
 * 这道题双指针就行了吧
 * runtime: 85.77%
 * memory:  37.27%
 */
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int num_size = nums.size();
        if (num_size == 1)
            return nums[0] >= target ? 1 : 0; 
        int sptr = 0, eptr = 1;
        if (nums[sptr] >= target) return 1;
        int sum = nums[0] + nums[1], min_len = 1e5 + 1;
        while (eptr < num_size) {
            if (nums[eptr] >= target) return 1;
            if (sum >= target) {
                min_len = std::min(min_len, eptr - sptr + 1);
                sum -= nums[sptr++];
            } else {
                ++ eptr;
                if (eptr >= num_size) break;
                sum += nums[eptr];
            }
        }
        return min_len == 1e5 + 1 ? 0 : min_len;
    }
};

int main(int argc, char** argv) {
    Solution sol;
    std::vector<int> arr = {2,3,1,2,4,3};
    sol.minSubArrayLen(7, arr);

    return 0;
}