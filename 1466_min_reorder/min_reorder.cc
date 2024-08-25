#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

/**
 * 有向图的问题，也即所有的路线最终都指向 0
 * 也即我们可以从0开始，把向外的路线全部 invert
 * 后续对向外路线的判断复杂一些。
 * 其实思路挺简单的
 * runtime: 82.52%
 * memory:  71.76%
 */
class Solution {
public:
    int minReorder(int n, vector<vector<int>>& connections) {
        std::vector<std::vector<uint16_t>> o_routes(n + 1);
        std::vector<std::vector<uint16_t>> i_routes(n + 1);
        // 所有出入信息
        for (const auto& conn: connections) {
            o_routes[conn[0]].emplace_back(conn[1]);
            i_routes[conn[1]].emplace_back(conn[0]);
        }
        int result = 0;
        std::vector<bool> accessed(n, false);
        std::deque<uint16_t> bfs = {0};
        while (!bfs.empty()) {
            uint16_t top = bfs.front();
            bfs.pop_front();
            
            accessed[top] = true;
            const auto& o_dests = o_routes[top], & i_dests = i_routes[top];
            for (int out_dest: o_dests) {
                if (accessed[out_dest]) continue;
                bfs.push_back(out_dest);
                result += 1;
            }
            for (int in_dest: i_dests) {
                if (accessed[in_dest]) continue;
                bfs.push_back(in_dest);
            }
        }
        return result;
    }
};

int main(int argc, char** argv) {
    Solution sol;

    return 0;
}