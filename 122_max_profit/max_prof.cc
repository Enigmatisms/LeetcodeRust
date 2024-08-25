#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


class Solution {
public:
    /**
     * 这是暴力解法，之后需要重写这道题
     * runtime: 781ms   5.49%
     * memory:  15.24MB 10.42%
     */
    int maxProfit(vector<int>& prices) {
        int days = prices.size();
        if (days == 1) return 0;
        std::vector<int> profit(prices.size(), 0);
        for (int i = days - 2; i >= 0; i--) {
            int cur_price = prices[i], max_prof = 0;
            for (int j = i + 1; j < days; j++) {
                int tar_price = prices[j];
                int new_prof = 0;
                if (tar_price > cur_price) {
                    new_prof = tar_price - cur_price;
                    if (j < days - 1) new_prof += profit[j + 1];
                } else {
                    new_prof = profit[j];
                }
                max_prof = std::max(max_prof, new_prof);
            }
            profit[i] = max_prof;
        }
        return profit[0];
    }
};

int main(int argc, char** argv) {
    Solution sol;

    return 0;
}