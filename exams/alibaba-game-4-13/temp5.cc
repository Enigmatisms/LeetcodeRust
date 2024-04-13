#include <iostream>
#include <vector>
using namespace std;

using Pair = std::pair<int, int>;
// 暴力dfs 先试试

int gcd(int a, int b) {
    while (b != 0) {
        int temp = a % b;
        a = b;
        b = temp;
    }
    return a;
}

class Solution {
private:
    int mini_p = 0;
    int maxi_p = 0;
    float mini_ratio = 1e6;
public:
    void dfs_solve_path(const std::vector<std::vector<Pair>>& adjs, int s, int t, int num_node) {
        std::vector<bool> accessed(num_node, false);
        dfs(adjs, accessed, s, t, 1e6, 1);
        if (mini_p) {
            int gcd_val = gcd(mini_p, maxi_p);
            mini_p /= gcd_val;
            maxi_p /= gcd_val;
            if (mini_p == 1) {
                printf("%d\n", maxi_p);
            } else {
                printf("%d/%d\n", maxi_p, mini_p);
            }
        } else {
            std::cout << "%%%" << std::endl;
        }
    }

    void dfs(
        const std::vector<std::vector<Pair>>& adjs, 
        std::vector<bool>& accessed,
        int node, int target, int min_path, int max_path
    ) {
        if (node == target) {
            float ratio = float(max_path) / float(min_path);
            if (ratio < mini_ratio) {
                mini_p = min_path;
                maxi_p = max_path;
                mini_ratio = ratio;
            }
            return;
        }
        accessed[node] = true;
        for (auto [to, cost]: adjs[node]) {
            if (accessed[to]) continue;
            // printf("from = %d, to = %d, cost = %d, min_path = %d, max_path = %d\n", node, to, cost, min_path, max_path);
            int local_min_path = std::min(cost, min_path);
            int local_max_path = std::max(cost, max_path);
            float ratio = float(local_max_path) / float(local_min_path);
            if (ratio > mini_ratio) continue;
            dfs(adjs, accessed, to, target, local_min_path, local_max_path);
        }
        accessed[node] = false;
    }
};

int main() {
    int num_data = 0;
    std::cin >> num_data;
    for (int i = 0; i < num_data; i++) {
        int n = 0, m = 0, s = 0, t = 0;
        std::cin >> n >> m;
        std::cin >> s >> t;
        --s;
        --t;
        std::vector<std::vector<Pair>> adjs(n);
        for (int j = 0; j < m; j++) {
            int from = 0, to = 0, cost = 0;
            std::cin >> from >> to >> cost;
            --from;
            --to;
            adjs[from].emplace_back(to, cost);
            adjs[to].emplace_back(from, cost);
        }
        Solution sol;
        sol.dfs_solve_path(adjs, s, t, n);
    }
    return 0; 
}