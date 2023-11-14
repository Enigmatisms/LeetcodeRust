#include <vector>
#include <iostream>

/**
 * 只能说是自己回忆起了Floyd算法：不断新增中间节点（开放中间节点），如果中间节点引入导致路径变短，则记录
 * runtime: 93.35%
 * memory:  73.42%
*/

class Solution {
using Array = std::vector<int>;
using Arrays = std::vector<Array>;
public:
    // 此题的重点在于跳过一些不必要的计算... 是否有方法在一边构建图的过程中就可以一边求解？
    int findTheCity(int n, Arrays& edges, int distanceThreshold) const {
        Arrays short_paths(n, Array(n, 200000));
        for (const auto& edge: edges) {
            int from = edge[0], to = edge[1], weight = edge[2];
            short_paths[from][to] = weight;
            short_paths[to][from] = weight;
        }
        for (int inte_city = 0; inte_city < n; inte_city ++) {
            for (int from = 0; from < n; from ++) {
                int to_inte_city = short_paths[from][inte_city];
                if (from == inte_city)
                    to_inte_city = 0;
                for (int to = from + 1; to < n; to ++) {
                    if (to == inte_city) continue;
                    int path_len = to_inte_city + short_paths[inte_city][to];
                    if (path_len < short_paths[from][to]) {
                        short_paths[from][to] = path_len;
                        short_paths[to][from] = path_len;
                    }
                }
            }
        }
        int min_path_num = 200, min_city = 0;
        for (int i = 0; i < n; i++) {
            const Array& paths = short_paths[i];
            int path_num = 0;
            for (int j = 0; j < n; j++) {
                // printf("%2d\t", paths[j] > 1000 ? -1 : paths[j]);
                if (i == j) continue;
                path_num += int(paths[j] <= distanceThreshold);
            }
            // printf("\n");
            if (path_num <= min_path_num) {
                min_city = i;
                min_path_num = path_num;
            }
        }
        // printf("min_num: %d\n", min_path_num);
        return min_city;
    }
};

int main() {
    Solution sol;
    std::vector<std::vector<int>> test1 = {{0,1,2},{0,4,8},{1,2,3},{1,4,2},{2,3,1},{3,4,1}};        // th = 2
    std::vector<std::vector<int>> test2 = {{0,1,3},{1,2,1},{1,3,4},{2,3,1}};                        // dist sh = 4
    std::vector<std::vector<int>> test3 =
        {{0,3,5},{2,3,7},{0,5,2},{0,2,5},{1,2,6},{1,4,7},{3,4,4},{2,5,5},{1,5,8}};                  // n=6, dist = 8279
    printf("City 1: %d\n", sol.findTheCity(5, test1, 2));
    printf("City 2: %d\n", sol.findTheCity(4, test2, 4));
    printf("City 3: %d\n", sol.findTheCity(6, test3, 8279));
    return 0;
}