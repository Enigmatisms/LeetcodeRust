#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/**
 * 下标要把我整吐了
 * runtime: 98.11%
 * memory:  23.58
 */

class Solution {
public:
    int maxTotalFruits(vector<vector<int>>& fruits, int startPos, int k) {
        int cur_pos = std::upper_bound(fruits.begin(), fruits.end(), startPos, [](int pos, const std::vector<int>& fruit) {
            return fruit.front() > pos;
        }) - fruits.begin() - 1;

        int fruit_len = fruits.size();
        std::vector<std::pair<int, int>> left_sum, right_sum;
        for (int i = cur_pos, cum_num = 0; i >= 0; i--) {
            const auto& fruit = fruits[i];
            int delta_pos = startPos - fruit[0];
            if (delta_pos > k) break;
            cum_num += fruit[1];
            left_sum.emplace_back(delta_pos, cum_num);
        }

        for (int i = std::max(cur_pos, 0), cum_num = 0; i < fruit_len; i++) {
            const auto& fruit = fruits[i];
            int delta_pos = fruit[0] - startPos;
            if (delta_pos > k) break;
            if (delta_pos < 0) continue;
            cum_num += fruit[1];
            right_sum.emplace_back(delta_pos, cum_num);
        }

        int max_fruit = 0;
        for (size_t i = 0; i < left_sum.size(); i++) {
            auto [delta_pos, fnum] = left_sum[i];
            int remain_step = k - (delta_pos << 1);
            if (remain_step <= 0) {
                max_fruit = std::max(max_fruit, fnum);
                continue;
            }
            int cur_pos = std::upper_bound(right_sum.begin(), right_sum.end(), remain_step, [](int pos, const std::pair<int, int>& fruit) {
                return fruit.first > pos;
            }) - right_sum.begin();
            if (!cur_pos) {
                max_fruit = std::max(max_fruit, fnum);
            } else {
                int fruit_num = fnum + right_sum[cur_pos - 1].second;
                if (right_sum[0].first == 0)
                    fruit_num -= right_sum[0].second;
                max_fruit = std::max(max_fruit, fruit_num);
            }
        }

        for (size_t i = 0; i < right_sum.size(); i++) {
            auto [delta_pos, fnum] = right_sum[i];
            int remain_step = k - (delta_pos << 1);
            if (remain_step <= 0) {
                max_fruit = std::max(max_fruit, fnum);
                continue;
            }
            int cur_pos = std::upper_bound(left_sum.begin(), left_sum.end(), remain_step, [](int pos, const std::pair<int, int>& fruit) {
                return fruit.first > pos;
            }) - left_sum.begin();
            if (!cur_pos) {
                max_fruit = std::max(max_fruit, fnum);
            } else {
                int fruit_num = fnum + left_sum[cur_pos - 1].second;
                if (left_sum[0].first == 0)
                    fruit_num -= left_sum[0].second;
                max_fruit = std::max(max_fruit, fruit_num);
            }
        }
        return max_fruit;
    }
};

int main(int argc, char** argv) {
    Solution sol;
    std::vector<std::vector<int>> fruits = {{200000,10000}};
    std::cout << sol.maxTotalFruits(fruits, 0, 200000) << std::endl;
    return 0;
}