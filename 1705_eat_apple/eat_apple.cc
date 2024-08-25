#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <unordered_map>
#include <unordered_set>
#include <queue>

using namespace std;

/**
 * 贪心: 让我想起了操作系统调度 --- 马上要 overdue 的任务立刻切换进行（抢占式？）
 *      先吃马上要过期的苹果
 * + 优先队列。
 * runtime: 98.41%
 * memory:  24.60%
 */
using Pair = std::pair<int, int>;
struct CompOperator {
    bool operator() (const Pair& p1, const Pair& p2) const {
        return p1.first > p2.first;
    }
};


class Solution {
public:
    int eatenApples(vector<int>& apples, vector<int>& days) {
        // min heap, first: day overdue, second: day
        std::priority_queue<Pair, std::vector<Pair>, CompOperator> que;
        int apple_eaten = 0, day_num = days.size();
        for (int i = 0; i < day_num; i++) {
            while (que.empty() == false && que.top().first == i)
                que.pop();
            int apple = apples[i];
            if (apple)
                que.emplace(i + days[i], i);
            if (!que.empty()) {
                int date = que.top().second;
                int& num_apples = apples[date];
                -- num_apples;
                ++ apple_eaten;
                if (!num_apples)
                    que.pop();
            }
        }
        for (int i = day_num; que.empty() == false; i++) {
            while (que.empty() == false && que.top().first == i)
                que.pop();
            if (!que.empty()) {
                int date = que.top().second;
                int& num_apples = apples[date];
                -- num_apples;
                ++ apple_eaten;
                if (!num_apples)
                    que.pop();
            }
        }
        return apple_eaten;
    }
};

int main(int argc, char** argv) {
    Solution sol;

    return 0;
}