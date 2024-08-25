#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <unordered_map>
#include <unordered_set>

using namespace std;

/**
 * 不用 DP 也可以做
 * runtime: 34.45%
 * memory:  15.37%
 */
class Solution {
public:
    // 用 prefix min / suffix max 解决
    int maxProfit(vector<int>& prices) {
        int price_size = prices.size();
        std::vector<short> min_vals(price_size, 1e4 + 1), max_vals(price_size, 0);
        min_vals[0] = prices[0];
        max_vals.back() = prices.back();
        for (int i = 1; i < price_size; i++) {
            min_vals[i] = std::min(min_vals[i - 1], short(prices[i]));
            int max_idx = price_size - i - 1;
            max_vals[max_idx] = std::max(max_vals[max_idx + 1], short(prices[max_idx]));
        }
        int max_diff = 0;
        for (int i = 1; i < price_size; i++)
            max_diff = std::max(max_vals[i] - min_vals[i - 1], max_diff);
        return max_diff;
    }

    // 一次遍历 这个思路更好
    // 99.14%
    // 91.32%
    int maxProfit_once(vector<int>& prices) {
        int price_size = prices.size();
        int min_val = prices[0], max_val = min_val, max_diff = 0;
        for (int i = 1; i < price_size; i++) {
            int cur_val = prices[i];
            if (cur_val > max_val) {
                max_val = cur_val;
                max_diff = std::max(max_val - min_val, max_diff);
            } else if (cur_val < min_val) {
                min_val = cur_val;
                max_val = min_val;
            }
        }
        return max_diff;
    } 
};

int main(int argc, char** argv) {
    Solution sol;

    return 0;
}