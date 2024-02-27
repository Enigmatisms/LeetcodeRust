#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/**
 * runtime: 100.00%
 * memory:  32.20%
 */
class Solution {
public:
    int findMin(const vector<int>& nums) {
        int sptr = 0, eptr = static_cast<int>(nums.size()) - 1, mptr = 0;
        if (nums[sptr] <= nums[eptr]) return nums.front();
        while (sptr != eptr) {      // first, find the rotated start
            mptr = (sptr + eptr) >> 1;
            if (nums[mptr] > nums[sptr])
                sptr = mptr;
            else
                eptr = mptr;
        }
        return nums[sptr + 1];
    }
};

int main(int argc, char** argv) {
    Solution sol;
    return 0;
}