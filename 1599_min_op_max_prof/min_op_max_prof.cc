#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <unordered_map>
#include <unordered_set>

using namespace std;

/**
 * 这是啥题啊，好傻逼啊，评论区说得好：
 * “难度极低质量极差的究极阅读理解题”
 * runtime: 98.14%
 * memory:  6.55%
 */
class Solution {
public:
    int minOperationsMaxProfit(vector<int>& customers, int boardingCost, int runningCost) {
        if (boardingCost * 4 <= runningCost) return -1;     // 总是入不敷出
        int max_prof = 0, min_op = -1, wait = 0, prof = 0;
        for (size_t i = 0; i < customers.size() || wait; i++) {
            if (i < customers.size())
                wait += customers[i];
            int board_num = std::min(wait, 4);
            wait -= board_num;
            prof += board_num * boardingCost - runningCost;
            if (prof > max_prof) {
                min_op = i + 1;
                max_prof = prof;
            }
        }
        return min_op;
    }
};

int main(int argc, char** argv) {
    Solution sol;
    std::vector<int> custs = {10, 10, 6, 4, 7};
    sol.minOperationsMaxProfit(custs, 3, 8);
    return 0;
}