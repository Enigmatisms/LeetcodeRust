#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

/**
 * 这题虽然是 hard 但是并不很难 
 * runtime: 95.94%
 * memory:  9.88%
 */
class Solution {
public:
    int candy(vector<int>& ratings) {
        int length = ratings.size();
        if (length == 1) return 1;
        std::vector<int> candies(length, 1);
        if (ratings[0] > ratings[1]) candies[0] = 2;
        int ptr = 0;
        // forward traverse
        for (ptr = 1; ptr < length - 1; ptr++) {
            int cur_v = ratings[ptr];
            if (cur_v > ratings[ptr - 1]) 
                candies[ptr] = candies[ptr - 1] + 1;
            else if (cur_v > ratings[ptr + 1])
                candies[ptr] = 2;
        }
        if (ratings[ptr] > ratings[ptr - 1]) 
            candies[ptr] = candies[ptr - 1] + 1;

        // backward traverse
        int sum = candies.back();
        for (ptr = length - 2; ptr >= 0; ptr--) {
            int cur_v = ratings[ptr];
            if (cur_v > ratings[ptr + 1]) {
                int next_plus = candies[ptr + 1] + 1;
                candies[ptr] = std::max(candies[ptr], next_plus);
            }
            sum += candies[ptr];
        }
        return sum;
    }
};

int main(int argc, char** argv) {
    Solution sol;
    std::vector<int> test = {1, 0, 2};
    int res = sol.candy(test);
    printf("res: %d\n", res);
    return 0;
}