#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <unordered_map>
#include <queue>

using namespace std;

/**
 * 思路大致是这样的，但是没有 AC 很可惜。实现的时候写出了会使得重复元素被加入的代码
 * bfs 的 stack 实现是否有问题？ 我发现官方解答和我的思路几乎一致，差异在我用 BFS，官解用优先队列（小顶堆）
 * 我总是会把问题想得很复杂。按照 priority_queue 的思路修改了
 * runtime: 97.41%
 * memory:  45.69%
 * 
 * 只能说到处是坑，最好找时间重新写一下
 * 最主要的就是 num_paths 以及 queue 怎么更新
 */
class Solution {
using i64 = long long;
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        std::vector<std::vector<std::pair<int, int>>> adjacents(n);
        // build adjacent map
        for (const std::vector<int>& road: roads) {
            adjacents[road[0]].emplace_back(road[1], road[2]);
            adjacents[road[1]].emplace_back(road[0], road[2]);
        }
        std::vector<i64> num_paths(n, 0), min_cost(n, INT64_MAX);
        min_cost.back()  = 0;
        num_paths.back() = 1;
        // construct min heap
        std::priority_queue<std::pair<i64, int>, std::vector<std::pair<i64, int>>, std::greater<std::pair<i64, int>>> queue;
        queue.emplace(0, n - 1);
        while (queue.empty() == false) {
            auto [cur_cost, idx] = queue.top();
            queue.pop();
            // 可能有后面的更新使得路径更短的情况，如果遇到更长的路径就直接跳过
            if (cur_cost > min_cost[idx]) continue;

            i64 cur_num = num_paths[idx];
            for (auto [tar_idx, cost]: adjacents[idx]) {
                i64 new_cost = cur_cost + cost, &tar_cost = min_cost[tar_idx];
                if (new_cost < tar_cost) {
                    tar_cost = new_cost;
                    num_paths[tar_idx] = cur_num;           // replace
                    queue.emplace(new_cost, tar_idx);       // 有更好的一定要进行传播
                } else if (new_cost == tar_cost) {
                    num_paths[tar_idx] = (num_paths[tar_idx] + cur_num) % i64(1e9 + 7);          // increment
                    // 何时需要传播，何时不需要传播 （emplace），为什么此处不需要 emplace?
                    // 由于 new_cost 本身就大于 cur_cost, 所以可以知道对应的node还没有被遍历到，在队列里
                    // 所以不需要新加入（反正新加入与原来也是一致的）
                }
            }
        }
        return static_cast<int>(num_paths.front());
    }
};

int main(int argc, char** argv) {
    Solution sol;
    // 重复相加的例子
    std::vector<std::vector<int>> paths = {{4, 3, 1}, {3, 2, 1}, {2, 1, 2}, {4, 1, 4}, {1, 0, 1}};
    int result = sol.countPaths(5, paths);
    std::cout << "Num paths: " << result << std::endl;
    return 0;
}