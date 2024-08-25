#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <unordered_map>
#include <unordered_set>

using namespace std;

/**
 * 我一开始觉得我的方法很好来着... 结果一看时间和内存，都被干爆了
 * 思路完全没有问题，就是这样做。但是实现很慢
 * runtime: (adjs 用 嵌套 vector + unordered_set) 5.79% -> (adjs 用 嵌套 vector) 12.40%  -> (是否访问查询换 vector 而不是 set) 24.79%
 * memory:  (adjs 用 嵌套 vector + unordered_set) 5.79% -> (adjs 用 嵌套 vector) 9.92%
 * 
 * 学一下并查集
 */
class Solution {
public:
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        int s_len = s.size();
        std::vector<std::vector<int>> adjs(s_len);
        for (const auto& pr: pairs) {
            int p1 = pr[0], p2 = pr[1];
            if (p1 == p2) continue;
            adjs[p1].emplace_back(p2);
            adjs[p2].emplace_back(p1);
        }

        // DFS 查连通分量
        std::vector<int> accessed(s_len, 0);
        for (int k = 0; k < s_len; k++) {
            if (accessed[k]) continue;
            std::vector<int> connected_id;
            std::vector<int> dfs_stack = {k};
            accessed[k] = 1;
            while (dfs_stack.empty() == false) {
                int value = dfs_stack.back();
                dfs_stack.pop_back();
                connected_id.emplace_back(value);

                for (int adj_node: adjs[value]) {
                    if (accessed[adj_node] == 1) continue;
                    dfs_stack.push_back(adj_node);
                    accessed[adj_node] = 1;
                }
            }
            if (connected_id.size() == 1) continue;
            std::sort(connected_id.begin(), connected_id.end());
            std::vector<char> connected_c;
            connected_c.reserve(connected_id.size());
            for (int idx: connected_id) connected_c.emplace_back(s[idx]);
            std::sort(connected_c.begin(), connected_c.end());
            for (size_t i = 0; i < connected_c.size(); i++)
                s[connected_id[i]] = connected_c[i];
        }
        return s;
    }
};

int main(int argc, char** argv) {
    Solution sol;

    return 0;
}