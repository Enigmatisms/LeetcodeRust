#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>

using namespace std;

/**
 * 
 * runtime: 53.47%
 * memory:  21.78%
 */
class Solution {
public:
    int reachableNodes(int n, vector<vector<int>>& edges, vector<int>& restricted) {
        std::vector<bool> accessed(n, false);
        for (int node_id: restricted)
            accessed[node_id] = true;
        std::unordered_map<int, std::vector<int>> mapping;
        for (const std::vector<int>& edge: edges) {
            int v1 = edge.front(), v2 = edge.back();
            mapping[v1].push_back(v2);
            mapping[v2].push_back(v1);
        }
        std::unordered_set<int> result;
        std::vector<int> stack = {0};
        while (stack.empty() == false) {
            int top_id = stack.back();
            stack.pop_back();
            accessed[top_id] = true;
            for (int tid: mapping[top_id]) {
                if (accessed[tid]) continue;
                result.emplace(tid);
                stack.push_back(tid);
            }
        }
        return result.size() + 1;
    }
};

int main(int argc, char** argv) {
    Solution sol;
    std::vector<std::vector<int>> edges = {{4,1},{1,3},{1,5},{0,5},{3,6},{8,4},{5,7},{6,9},{3,2}};
    std::vector<int> restricted = {2, 7};
    int res = sol.reachableNodes(10, edges, restricted);
    printf("Result: %d\n", res);
    return 0;
}