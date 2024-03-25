#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <unordered_map>
#include <unordered_set>

using namespace std;

/** 
 * 这道题不该算中等题，太简单了
 * runtime: 94.59%
 * memory:  86.49%
 */
class Solution {
public:
    // 这个应该算是访存优化了的
    int minDistance(int height, int width, vector<int>& tree, vector<int>& squirrel, vector<vector<int>>& nuts) {
        int sqr_x = squirrel[0], sqr_y = squirrel[1], tree_x = tree[0], tree_y = tree[1];
        int total_dist = 0, min_diff = INT32_MAX;
        for (size_t i = 0; i < nuts.size(); i++) {
            int nut_x = nuts[i][0], nut_y = nuts[i][1];
            int nut_tree = abs(nut_x - tree_x) + abs(nut_y - tree_y);
            total_dist  += nut_tree << 1;
            int diff = abs(nut_x - sqr_x) + abs(nut_y - sqr_y) - nut_tree;
            min_diff = std::min(diff, min_diff);
        }
        return total_dist + min_diff;
    }

    // 没有优化的
    int minDistance_nonop(int height, int width, vector<int>& tree, vector<int>& squirrel, vector<vector<int>>& nuts) {
        int sqr_x = squirrel[0], sqr_y = squirrel[1], tree_x = tree[0], tree_y = tree[1];
        int total_dist = 0, result = INT32_MAX;
        for (size_t i = 0; i < nuts.size(); i++) {
            int nut_x = nuts[i][0], nut_y = nuts[i][1];
            total_dist  += (abs(nut_x - tree_x) + abs(nut_y - tree_y)) << 1;
        }
        for (size_t i = 0; i < nuts.size(); i++) {
            int nut_x = nuts[i][0], nut_y = nuts[i][1];
            int dist = total_dist - abs(nut_x - tree_x) - abs(nut_y - tree_y);
            dist    += abs(nut_x - sqr_x) + abs(nut_y - sqr_y);
            result = std::min(dist, result);
        }
        return result;
    }
};

int main(int argc, char** argv) {
    Solution sol;

    return 0;
}