#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>

void dfs(const std::vector<bool>& val, const std::vector<std::vector<int>>& adj, 
    std::unordered_set<int>& visited, std::unordered_map<int, std::unordered_map<int, int>>& cost, int u, int parent) {
    visited.emplace(u);
    for (int v: adj[u]) {
        if (v != parent && visited.count(v) == 0) {                     // 邻居未访问
            int par_cost = cost[parent][u] + (val[u] != val[v]);        // 不相同的属性才需要增加cost
            cost[u][v]   = par_cost;
            dfs(val, adj, visited, cost, v, u);
        }
    }
}

void calculate_total(int n, const std::vector<bool>& val, const std::vector<std::vector<int>>& adj) {
    std::unordered_map<int, std::unordered_map<int, int>> cost;
    for (int i = 0; i < n; i++) {
        std::unordered_set<int> visited;
        dfs(val, adj, visited, cost, i, -1);
    }
    int total = 0;
    for (auto& p1: cost) {
        for (auto& p2: p1.second) {
            total += p2.second;
        }
    }
    std::cout << total << std::endl;
}

int main(int argc, char** argv) {
    int num_nodes = 0;
    std::cin >> num_nodes;
    std::vector<bool> val(num_nodes);
    std::string line;
    std::cin >> line;
    std::vector<std::vector<int>> adj(num_nodes);
    for (int i = 0; i < num_nodes; i++)
        val[i] = line[i] == '-';
    int from = 0, to = 0;
    for (int i = 0; i < num_nodes - 1; i++) {
        std::cin >> from >> to;
        adj[from - 1].push_back(to - 1);
        adj[to - 1].push_back(from - 1);
    } 
    calculate_total(num_nodes, val, adj);
    return 0;
}