#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <unordered_map>
#include <unordered_set>

using namespace std;

/**
 * runtime: 54.84
 * memory:  5.95%
 */
class Solution {
public:
    long long largestSquareArea(vector<vector<int>>& bottomLeft, vector<vector<int>>& topRight) {
        std::vector<std::vector<int>> rects(bottomLeft.size());
        for (size_t i = 0; i < bottomLeft.size(); i++)
            rects[i] = {bottomLeft[i][0], bottomLeft[i][1], topRight[i][0], topRight[i][1]};
        // sorted by the bottom right x value
        std::sort(rects.begin(), rects.end(), [](const std::vector<int>& r1, const std::vector<int>& r2) {
            return r1.front() < r2.front();
        });
        long long min_len_max = 0;
        for (size_t i = 0; i < bottomLeft.size(); i++) {
            const std::vector<int>& curr = rects[i];
            int r1_min = std::min(curr[2] - curr[0], curr[3] - curr[1]);
            for (size_t j = i + 1; j < bottomLeft.size(); j++) {
                // judge if rect[i] and rect[j] overlap and the intersection is greater than the current max
                // sort 不一定必要
                if (curr[2] <= rects[j].front()) break;
                long long isect_len = intersect_min(curr, rects[j], r1_min);
                min_len_max = std::max(min_len_max, isect_len);
            }
        }
        return min_len_max * min_len_max;
    }

    int intersect_min(const std::vector<int>& r1, const std::vector<int>& r2, int r1_min = 1e7) const {
        if (r1[0] < r2[2] && r1[1] < r2[3] && r1[2] > r2[0] && r1[3] > r2[1]) {
            if (r2[1] >= r1[1])
                r1_min = std::min(r1[3] - r2[1], r1_min);
            else
                r1_min = std::min(r2[3] - r1[1], r1_min);
            r1_min = std::min(r2[3] - r2[1], r1_min);           // self height
            r1_min = std::min(r2[2] - r2[0], r1_min);           // self length
            r1_min = std::min(r1[2] - r2[0], r1_min);
            return r1_min;
        }
        return 0;
    }
};

int main(int argc, char** argv) {
    Solution sol;
    std::vector<std::vector<int>> bottoms = {{3, 2}, {1, 1}};
    std::vector<std::vector<int>> ups     = {{4, 5}, {5, 4}};
    sol.largestSquareArea(bottoms, ups);
    return 0;
}