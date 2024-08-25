#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <queue>

using namespace std;

/**
 * Dijkstra 还是比较暴力的
 * Dijkstra 早忘了，还是手推推出来的...
 * 话说手推了一下 Floyd 觉得更新图很困难，就没实现
 * runtime: 41.98%
 * memort:  5.46%
*/
class Graph {
using Pair = std::pair<int, int>;
private:
    // 当前节点保存入边（的来源节点以及对应的 cost）
    std::vector<std::vector<Pair>> receives;
public:
    Graph(int n, vector<vector<int>>& edges): receives(n) {
        for (auto edge: edges) {
            addEdge(edge);
        }
    }
    
    void addEdge(vector<int> edge) {
        int from_idx = edge[0], to_idx = edge[1], cost = edge[2];
        receives[to_idx].emplace_back(from_idx, cost);
    }
    
    int shortestPath_pure_queue(int node1, int node2) {
        // Dijkstra 我们先不搞这么麻烦的，先能写出来
        // 以下小顶堆，first 存累积最短路长度，second 存当前节点 ID
        std::priority_queue<Pair, std::vector<Pair>, std::greater<>> queue;
        std::vector<bool> accessed(receives.size(), false);
        queue.emplace(0, node2);
        int min_cost = INT32_MAX;
        while (queue.empty() == false) {
            auto [cost, node_id] = queue.top();
            queue.pop();
            if (node_id == node1)
                min_cost = std::min(min_cost, cost);
            if (accessed[node_id]) continue;        // 一个 node id 可能在队列里出现多次
            accessed[node_id] = true;
            for (auto [from_idx, path_cost]: receives[node_id]) {
                queue.emplace(cost + path_cost, from_idx);
            }
        }
        return min_cost == INT32_MAX ? -1 : min_cost;
    }

    int shortestPath(int node1, int node2) {
        // Dijkstra 我们先不搞这么麻烦的，先能写出来
        // 以下小顶堆，first 存累积最短路长度，second 存当前节点 ID
        std::priority_queue<Pair, std::vector<Pair>, std::greater<>> queue;
        std::vector<int> costs(receives.size(), INT32_MAX);
        queue.emplace(0, node2);
        costs[node2] = 0;
        while (queue.empty() == false) {
            auto [cost, node_id] = queue.top();
            queue.pop();
            if (cost > costs[node_id]) continue;
            for (auto [from_idx, path_cost]: receives[node_id]) {
                int cur_cost = cost + path_cost;
                if (cur_cost < costs[from_idx]) {
                    costs[from_idx] = cur_cost;
                    queue.emplace(cur_cost, from_idx);
                }
            }
        }
        return costs[node1] == INT32_MAX ? -1 : costs[node1];
    }
};

int main(int argc, char** argv) {

    return 0;
}