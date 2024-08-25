#include <queue>
#include <cmath>
#include <vector>
#include <algorithm>
#include <iostream>

/**
 * 权当复习堆了，虽然不是自己手写： 
 * rumtime: 96.51%
 * memory:  14.73%
 */

class Solution {
public:
    long long pickGifts(const std::vector<int>& gifts, int k) const {
        std::priority_queue<int, std::vector<int>> queue;
        for (int v: gifts) {
            queue.push(v);
        }
        for (int i = 0; i < k; i++) {
            int gift_num = queue.top();
            int new_gift_num = static_cast<int>(std::floor(std::sqrt(gift_num)));
            queue.pop();
            queue.push(new_gift_num);
        }
        long long total_num = 0;
        while (queue.empty() == false) {
            total_num += static_cast<int>(queue.top());
            queue.pop();
        }
        return total_num;
    }
};

int main() {
    Solution sol;
    std::vector<int> gifts{25,64,9,4,100};
    printf("Gifts left: %lld\n", sol.pickGifts(gifts, 4));
    return 0;
}