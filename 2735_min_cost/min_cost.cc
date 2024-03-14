#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

/**
 * 这道题暴力法还是... 可以做的
 * runtime: 93.82%
 * memory:  13.70%
 */
class Solution {
public:
    long long minCost(vector<int>& nums, int x) {
        int num_len = nums.size();
        long long min_cost = 0;
        std::vector<int> last_pos(num_len, 0);
        std::iota(last_pos.begin(), last_pos.end(), 0);
        for (int i = 0; i < num_len; i++)
            min_cost += nums[i];
        for (int move = 1; move < num_len; move++) {
            long long cur_cost = min_cost;
            for (int i = 0; i < num_len; i++) {
                int& index = last_pos[i], new_index = i + move;
                if (new_index >= num_len) new_index -= num_len;
                int old_v = nums[index], new_v = nums[new_index];
                if (new_v < old_v) {
                    cur_cost += new_v - old_v;
                    index = new_index;
                }
            }
            cur_cost += x;
            min_cost = std::min(min_cost, cur_cost);
        }
        return min_cost;
    }
};

int main(int argc, char** argv) {
    Solution sol;

    return 0;
}