#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/**
 * 这道题非常无脑
 * runtime: 89.43%
 * memory:  90.67%
 */
class Solution {
private:
    int target;
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        std::vector<std::vector<int>> results;
        std::vector<int> path;
        target = graph.size() - 1;
        path.reserve(graph.size());
        dfs(graph, results, path, 0);
        return results;
    }

    void dfs(
        const vector<vector<int>>& graph,
        std::vector<std::vector<int>>& results, 
        std::vector<int>& path, int node
    ) const {
        path.push_back(node);
        if (node == target) {
            results.push_back(path);
            path.pop_back();
            // 无环
            return;
        }
        for (int to_node: graph[node])
            dfs(graph, results, path, to_node);
        path.pop_back();
    }
};

int main(int argc, char** argv) {
    Solution sol;

    return 0;
}