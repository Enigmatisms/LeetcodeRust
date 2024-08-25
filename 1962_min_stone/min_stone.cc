#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

/**
 * 思路没什么难度
 * runtime: 62.33%
 * memory:  25.00%
 */
class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
        int sum = 0;
        std::priority_queue<int, std::vector<int>> queue;
        for (int v: piles) {
            queue.push(v);
            sum += v;
        }
        for (int i = 0; i < k; i++) {
            int top_num = queue.top(), subtract = top_num >> 1;
            queue.pop();
            sum -= subtract;
            queue.push(top_num - subtract);
        }
        return sum;
    }
};

int main(int argc, char** argv) {
    Solution sol;

    return 0;
}