#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <set>

using namespace std;

/**
 * (1) 想法1：每次传播给邻接节点
 * 每次只将修改了的 ancestor 数组传播给邻接的节点
 * 使用什么数据结构？set 估计可以，毕竟规模不大，追求 unordered_set 效率估计也没那么高
 * 所有值传播给邻接节点可能会造成很大的开销..
 * (2) 想法2：DFS + 记录（如果某个节点之前 DFS 传播过，就不用传播本节点的 ID，否则需要传播一个 vector）
 * 想法（2）超时了
 * 这道题之前没接触过对应的思想（拓扑排序）
 * 所以做不出来很正常... 我的解法是 TLE 解，跑到 48/80 就超时寄了
 * runtime: TLE
 * memory:  /
 */
class Solution {
public:
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        std::unordered_map<int, std::vector<int>> adjs(n);
        for (const auto& edge: edges) {
            int from = edge[0], to = edge[1];
            adjs[from].push_back(to);
        }
        std::vector<std::set<int>> ancestors(n);
        std::vector<bool> dfs_access(n, false);
        for (auto cit = adjs.cbegin(); cit != adjs.cend(); ++cit) {
            if (dfs_access[cit->first] == true) continue;
            std::vector<int> props;
            dfs(adjs, ancestors, dfs_access, props, cit->first);
        }
        std::vector<std::vector<int>> results;
        results.reserve(n);
        for (int i = 0; i < n; i++) {
            int size = ancestors[i].size();
            results.emplace_back(ancestors[i].begin(), ancestors.end());
        }
        return results;
    }

    void dfs(
        const std::unordered_map<int, std::vector<int>>& adjs, 
        std::vector<std::set<int>>& ancestors,
        std::vector<bool>& accessed, 
        std::vector<int>& propagate,
        int start
    ) {
        for (int prop: propagate)
            ancestors[start].emplace(prop);
        auto it = adjs.find(start);
        if (it == adjs.cend()) return;
        bool this_accessed = accessed[start];
        if (!this_accessed) {
            propagate.push_back(start);
            accessed[start] = true;
        }
        for (int to_idx: it->second)
            dfs(adjs, ancestors, accessed, propagate, to_idx);
        if (!this_accessed)
            propagate.pop_back();
    }
};

int main(int argc, char** argv) {
    Solution sol;

    return 0;
}