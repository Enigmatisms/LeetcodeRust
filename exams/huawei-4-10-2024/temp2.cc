#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>

std::unordered_set<int> can_access;

void dfs(const std::vector<std::unordered_map<int, int>>& adjs, int start, std::vector<int>& nodes) {
    can_access.erase(start);
    nodes.emplace_back(start);
    const std::unordered_map<int, int>& row_ref = adjs[start];
    for (auto it = row_ref.begin(); it != row_ref.end(); it++) {
        if (it->first == start || it->second == 0) continue;
        if (can_access.count(it->first) == 0) continue;         // can not access anymore
        dfs(adjs, it->first, nodes);
    }
}

int main(int argc, char** argv) {
    int num_of_node = 0;
    std::cin >> num_of_node;
    std::vector<std::unordered_map<int, int>> adjs(num_of_node);
    for (int i = 0; i < num_of_node; i++) {
        for (int j = 0; j < num_of_node; j++) {
            int sim_val = 0;
            std::cin >> sim_val;
            if (!sim_val) continue;
            adjs[i][j] = sim_val;
            adjs[j][i] = sim_val;
        }
    }
    for (int i = 0; i < num_of_node; i++)
        can_access.emplace(i);
    std::vector<int> all_sims;
    while (can_access.empty() == false) {
        std::vector<int> nodes;
        dfs(adjs, *can_access.begin(), nodes);
        int sim_sum = 0;
        for (size_t i = 0; i < nodes.size(); i++) {
            int node_i = nodes[i];
            for (size_t j = i + 1; j < nodes.size(); j++)
                sim_sum += adjs[node_i][nodes[j]];
        }
        all_sims.emplace_back(sim_sum);
    }
    std::sort(all_sims.begin(), all_sims.end(), std::greater<int>{});
    std::cout << all_sims[0];
    for (size_t i = 1; i < all_sims.size(); i++)
        std::cout << " " << all_sims[i];
    std::cout << std::endl;
    return 0;
}