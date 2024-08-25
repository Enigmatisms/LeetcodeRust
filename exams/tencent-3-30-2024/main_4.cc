#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

// 不想写 std::tuple std::get 很烦
struct Pair {
    int cur_id;         // 当前节点 id
    int min_cost;       // 到达此节点的最小 cost
    int method;         // 到达这个此节点，产生min cost的对应途径
    Pair (int id, int cost, int mth): cur_id(id), min_cost(cost), method(mth) {}
};

struct Tuple3CompareFunctor {
    bool operator() (const Pair& t1, const Pair& t2) const {
        return t1.min_cost > t2.min_cost;
    }
};

// 天啊，好恶心的...
int dijkstra_state(int num_cities, std::vector<std::vector<std::vector<int>>>& adjacents, std::vector<int>& change) {
    // DP[0][i] 代表从 n 出发，到达 i 时乘坐火车的最小代价
    // DP[1][i] 代表从 n 出发，到达 i 时乘坐飞机的最小代价
    // 需要 priority_queue
    std::vector<std::vector<int>> dp(2, std::vector<int>(num_cities, INT32_MAX));
    dp[0].back() = 0;
    dp[1].back() = 0;
    std::priority_queue<Pair, std::vector<Pair>, Tuple3CompareFunctor> queue;
    queue.emplace(num_cities - 1, 0, 0);
    queue.emplace(num_cities - 1, 0, 1);
    while (queue.empty() == false) {
        auto top = queue.top();
        queue.pop();
        if (top.min_cost > dp[top.method][top.cur_id]) continue;
        const auto& out_dirs = adjacents[top.cur_id];
        for (const auto& way: out_dirs) {
            int to_city = way[0], path_cost = way[1], method = way[2], to_cost = 0;
            if (method != top.cur_id)         // 到达对应节点产生最小值的方法不是当前通路的方法
                to_cost = top.min_cost + change[to_city] + path_cost;
            else
                to_cost = top.min_cost + path_cost;
            if (to_cost < dp[method][to_city]) {
                dp[method][to_city] = to_cost;
                queue.emplace(to_city, to_cost, method);
            }
        } 
    }
    return std::min(dp[0][0], dp[1][0]);
}

int main(int argc, char** argv) {
    int num_cities = 0, num_routes = 0;
    std::cin >> num_cities >> num_routes;
    std::vector<int> change_time(num_cities);
    std::vector<std::vector<std::vector<int>>> adjacents(num_cities);
    for (int i = 0; i < num_cities; i++)
        std::cin >> change_time[i];
    for (int i = 0; i < num_routes; i++) {
        int from = 0, to = 0, cost = 0, method = 0;
        std::cin >> from >> to >> cost >> method;
        -- method;
        -- from;
        -- to;
        adjacents[from].push_back({to, cost, method});
        adjacents[to].push_back({from, cost, method});
    }
    std::cout << dijkstra_state(num_cities, adjacents, change_time) << std::endl;
    return 0;
}