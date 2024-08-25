#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <unordered_map>
#include <unordered_set>

using namespace std;

/**
 * 显然有暴力法，但是不暴力的方法很好想到... 秒杀了
 * 但目前我这个思路还是复杂了
 * runtime: 94.81%
 * memory:  28.57%
 */
class Solution {
public:
    vector<int> minOperations(string boxes) {
        int box_size = boxes.size();
        std::vector<short> ball_pos;
        std::vector<int> result(box_size, 0);
        ball_pos.reserve(box_size);
        int sum = 0, num_ball = 0;
        for (int i = 0; i < box_size; i++) {
            if (boxes[i] == '1') {
                ball_pos.emplace_back(i);
                sum += i;
            }
        }
        num_ball  = ball_pos.size();
        result[0] = sum;
        for (int i = 1; i < box_size; i++) {
            int upper = std::upper_bound(ball_pos.begin(), ball_pos.end(), i) - ball_pos.begin();
            if (upper) {
                int cur_equal = ball_pos[upper - 1] == i;
                sum += 2 * (upper - cur_equal) - num_ball;
            } else {
                sum -= num_ball;
            }
            result[i] = sum;
        }
        return result;
    }
};

int main(int argc, char** argv) {
    Solution sol;

    return 0;
}