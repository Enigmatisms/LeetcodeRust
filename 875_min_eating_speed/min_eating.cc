#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/**
 * 边缘问题处理得很差
 * runtime: 
 * memory:  
 */
class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        if (piles.size() == 1)
            return (piles[0] + h - 1) / h;          // 向上取整
        std::sort(piles.begin(), piles.end());
        if (piles.size() == h) return piles.back();
        int64_t min_speed = piles.back(), max_speed = min_speed, pile_len = piles.size();
        for (int i = pile_len - 2; i >= 0; i--) {
            int64_t pile = piles[i], hours_required = i + 1;
            auto search_start = piles.begin() + i + 1;
            for (int64_t cur_speed = pile * 2, k = 2; search_start != piles.end(); cur_speed += pile, k++) {
                auto spot = std::upper_bound(search_start, piles.end(), cur_speed);
                int64_t num_pile = spot - search_start;
                hours_required += num_pile * k;
                search_start = spot;
            }
            if (hours_required > h) {   // 说明当前速度太小，吃不完。那么我们可以从相邻的两个pile 之间，找一个中间速度
                min_speed = intermediate_speed(piles, piles[i], piles[i + 1], i, h);
                break;      
            } else if (i == 0) {        // piles[0] 到 speed = 1 的排查
                min_speed = intermediate_speed(piles, 1, piles[0], -1, h);
            }
            min_speed = pile;
        }
        return min_speed;
    }

    int intermediate_speed(vector<int>& piles, int64_t s_speed, int64_t e_speed, int index, int h) {
        int64_t speed = (s_speed + e_speed) >> 1;
        while (e_speed != s_speed) {
            int hours_required = index + 1;
            auto search_start = piles.begin() + index + 1;
            for (int64_t cur_speed = speed * 2, k = 2; search_start != piles.end(); cur_speed += speed, k++) {
                auto spot = std::upper_bound(search_start, piles.end(), cur_speed);
                int64_t num_pile = spot - search_start;
                hours_required += num_pile * k;
                search_start = spot;
            }
            if (hours_required > h) {
                s_speed = speed + 1;
                speed   = (s_speed + e_speed) >> 1;
            } else {
                e_speed = speed;
                speed   = (speed + s_speed) >> 1;
            }
        }
        return speed;
    }
};

int main(int argc, char** argv) {
    Solution sol;

    return 0;
}