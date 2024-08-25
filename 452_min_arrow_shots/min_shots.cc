#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <unordered_map>
#include <unordered_set>

using namespace std;

/**
 * 我的方法复杂度是 O(nm), m 是最后存留的交集的最大值， 空间复杂度 O(m)
 * 解答说可以到 O(nlogn), O(logn) 用贪心...
 * 方法很妙，但不如我这个好想（虽然慢）
 * runtime: 14.72%
 * memory:  18.70%
 */
class Solution {
public:
    // find the minimum number of disjoint intervals (intersection)
    int findMinArrowShots(vector<vector<int>>& points) {
        std::sort(points.begin(), points.end(), [](const std::vector<int>& v1, const std::vector<int>& v2){
            return v1.front() < v2.front();
        });
        std::vector<std::vector<int>> intervals;
        for (const std::vector<int>& vec: points) {
            int vs = vec.front(), ve = vec.back();
            bool has_intersect = false;
            for (std::vector<int>& interv: intervals) {
                // check whether two intervals intersect
                bool s_inside = vs <= interv.back() && vs >= interv.front();
                bool e_inside = ve <= interv.back() && ve >= interv.front();
                if (s_inside || e_inside) {     // update
                    has_intersect = true;
                    if (s_inside)
                        interv.front() = vs;
                    if (e_inside)
                        interv.back()  = ve;
                }
            }
            if (!has_intersect)
                intervals.push_back(vec);
        }
        // for (const std::vector<int>& interv: intervals) {
        //     printf("[%d, %d]\n", interv.front(), interv.back());
        // }
        return intervals.size();
    }
};

int main(int argc, char** argv) {
    Solution sol;
    std::vector<std::vector<int>> balls = {{3,9},{7,12},{3,8},{6,8},{9,10},{2,9},{0,9},{3,9},{0,6},{2,8}};
    printf("Arrows: %d\n", sol.findMinArrowShots(balls));
    return 0;
}