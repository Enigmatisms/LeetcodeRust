#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

/**
 * 难点在于：需要判断当前在前面还是后面取的
 * 如果雇佣了后半的人，说明后半可以继续加新人
 * 
 * 一遍过了，但是很慢，为什么
 * runtime: 5.02%
 * memory:  5.02%
 * 
 * std::deque 非常慢，上面是 deque，下面是 vector
 * 
 * runtime: 70.26%
 * memory:  54.26%
 */
template <typename T>
using Array = std::vector<T>;
class Solution {
public:
    long long totalCost(vector<int>& costs, int k, int candidates) {
        using Pair = std::pair<int, bool>;
        long long result = 0;
        int num_costs = costs.size();
        if (num_costs > candidates * 2) {
            auto comp_func = [](const Pair& v1, const Pair& v2) { return v1.first > v2.first; };
            std::priority_queue<std::pair<int, bool>, Array<Pair>, decltype(comp_func)> min_heap(comp_func);
            for (int i = 0; i < candidates; i++)
                min_heap.push(Pair(costs[i], true));
            for (int i = 1; i <= candidates; i++)
                min_heap.push(Pair(costs[num_costs - i], false));
            int sptr = candidates, eptr = num_costs - candidates - 1;
            for (int i = 0; i < k; i++) {
                auto [cost, is_front] = min_heap.top();
                min_heap.pop();
                result += cost;
                if (eptr < sptr) continue;
                if (is_front) {                 // sptr 与 eptr 指向的位置都是没添加的，只有 eptr < sptr 时所有的 elem 都被添加完成了
                    min_heap.push(Pair(costs[sptr], true));
                    ++ sptr;
                } else {
                    min_heap.push(Pair(costs[eptr], false));
                    -- eptr;
                }
            }
        } else {
            std::priority_queue<int, Array<int>, std::greater<>> min_heap;
            for (int cost: costs) min_heap.push(cost);
            for (int i = 0; i < k; i++) {
                result += min_heap.top();
                min_heap.pop();
            }
        }
        return result;
    }
};

int main(int argc, char** argv) {
    Solution sol;

    return 0;
}