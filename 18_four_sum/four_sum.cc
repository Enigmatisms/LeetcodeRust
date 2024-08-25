#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <unordered_map>
#include <unordered_set>

using namespace std;

/** 
 * K 数和问题，使用双指针可以把 O(N^K) 降为 O(N^{K - 1})
 * runtime: 44.15%
 * memory:  51.87%
 */
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int num_size = nums.size();
        if (num_size < 4) return {};
        std::sort(nums.begin(), nums.end());
        int sp = 0, ep = num_size - 1;
        std::vector<std::vector<int>> results;
        for (int sp = 0; sp < num_size - 3;) {
            long long cur_sp = nums[sp];
            for (int ep = num_size - 1; ep >= sp + 3;) {
                int inner_sp = sp + 1, inner_ep = ep - 1;
                long long cur_ep = nums[ep];
                long long residual = static_cast<long long>(target) - (cur_sp + cur_ep);
                while (inner_sp < inner_ep) {
                    long long cur_isp = nums[inner_sp], cur_iep = nums[inner_ep], res = cur_isp + cur_iep;
                    bool move_isp = res <= residual, move_iep = res >= residual; 
                    if (move_isp && move_iep)
                        results.push_back({(int)cur_sp, (int)cur_isp, (int)cur_iep, (int)cur_ep});
                    if (move_isp) {
                        for (inner_sp = inner_sp + 1; inner_sp < inner_ep; inner_sp++) {
                            if (nums[inner_sp] != cur_isp) break;
                        }
                    }
                    if (move_iep) {
                        for (inner_ep = inner_ep - 1; inner_ep > inner_sp; inner_ep--) {
                            if (nums[inner_ep] != cur_iep) break;
                        }
                    }
                }
                for (ep = ep - 1; ep >= sp + 3 && nums[ep] == cur_ep; ep --);
            }
            for (sp = sp + 1; sp < num_size - 3 && nums[sp] == cur_sp; sp ++);
        }
        return results;
    }
};

int main(int argc, char** argv) {
    Solution sol;

    return 0;
}