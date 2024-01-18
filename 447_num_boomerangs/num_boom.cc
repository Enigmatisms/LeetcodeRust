#include <vector>
#include <unordered_map>
#include <iostream>

/**
 * 这道题很简单...
 * 只要记住：判断点与点之间的距离是没有捷径的（非最邻近搜索问题），一定是 O(n^2)
 * runtime: 97.19%
 * memory:  26.99%
*/

class Solution {
public:
    int numberOfBoomerangs(const std::vector<std::vector<int>>& points) const noexcept {
        int result = 0;
        std::vector<int> power_dist(points.size());
        for (int i = 0; i < points.size(); i++) {
            power_dist[i] = points[i].front() * points[i].front() + points[i].back() * points[i].back();
            // printf("Power dist: %d\n", power_dist[i]);
        }
        for (int i = 0; i < points.size(); i++) {
            std::unordered_map<int, int> mapping;
            const int cx = points[i].front(), cy = points[i].back();
            for (int j = 0; j < points.size(); j++) {
                if (i == j) continue;
                int dist = power_dist[i] + power_dist[j];
                dist -= (cx * points[j].front() + cy * points[j].back()) << 1;
                if (dist < 0) dist = -dist;
                if (mapping.count(dist) == 0) {
                    mapping[dist] = 1;
                } else {
                    mapping[dist]++;
                }
            }
            for (const auto& [dist, num]: mapping) {
                // printf("i = %d, Distance : %d, num: %d\n", i, dist, num);
                result += num * (num - 1);
            }
        }
        return result;
    }
};

int main(int argc, char** argv) {
    Solution sol;
    
    std::vector<std::vector<int>> points{{0, 0}, {1, 0}, {2, 0}};
    int res = sol.numberOfBoomerangs(points);
    printf("Result: %d\n", res);
    return 0;
}