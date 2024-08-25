#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <unordered_map>
#include <unordered_set>

using namespace std;

/**
 * 这.. 中等？这不是简单题？
 * runtime: 97.94%
 * memory:  30.93%
 */
class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        long long last_start = -1, num_len = nums.size(), result = 0;
        for (int i = 0; i < num_len; i++) {
            if (!nums[i]) {
                if (last_start == -1)
                    last_start = i;
            } else {
                if (last_start != -1) {
                    long long num_zero = i - last_start;
                    result += (1ll + num_zero) * num_zero >> 1ll;
                    last_start = -1;
                }
            }
        }
        if (last_start != -1) {
            long long num_zero = num_len - last_start;
            return result + ((1ll + num_zero) * num_zero >> 1ll);
        }
        return result;
    }
};

int main(int argc, char** argv) {
    Solution sol;

    return 0;
}