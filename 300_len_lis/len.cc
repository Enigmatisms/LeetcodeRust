#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/**
 * max_num[i] 表示：以 nums[i] 结尾的所有升序子序列里长度的最大值
 * runtime: 76.14%
 * memory:  34.95%
 */
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int num_len = static_cast<int>(nums.size());
        std::vector<int> max_num(num_len, 0);
        max_num.front() = 1;
        for (int i = 1; i < num_len; i++) {
            int num_i = nums[i], best = 1;
            for (int j = 0; j < i; j++) {
                if (nums[j] < num_i) {
                    best = std::max(max_num[j] + 1, best);
                }
            }
            max_num[i] = best;
        }
        return *std::max_element(max_num.begin(), max_num.end());
    }
};

int main(int argc, char** argv) {
    Solution sol;

    return 0;
}