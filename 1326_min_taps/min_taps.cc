#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

/**
 * 怎么说呢，这道题... 容易不能AC
 * 我们进行两次排序，每次查找，对于同样灌溉起点的水龙头
 * 寻找最大的灌溉终点，并且：如果出现cover的情况，直接返回，否则记录这个最大的灌溉终点
 * 而灌溉起点超过了上一个选中的最大区间水龙头时，需要更新最大区间水龙头
 * runtime: 64.17%
 * memory:  34.17%
 */
class Solution {
public:
    int minTaps(int n, vector<int>& ranges) {
        std::vector<std::pair<int, int>> taps;
        taps.reserve(n + 1);
        for (int i = 0; i <= n; i++) {
            int range = ranges[i];
            taps.emplace_back(std::max(i - range, 0), i + range);
        }
        std::sort(taps.begin(), taps.end(), 
            [](const std::pair<int, int>& p1, const std::pair<int, int>& p2) {
                return p1.second < p2.second;
            }
        );
        std::stable_sort(taps.begin(), taps.end(), 
            [](const std::pair<int, int>& p1, const std::pair<int, int>& p2) {
                return p1.first < p2.first;
            }
        );
        if (taps[0].first > 0) return -1;
        int idx = 0, sp = 0, max_ep = 0, tap_ep = -1, result = 0;
        while (idx <= n) {
            int sp = taps[idx].first;
            if (sp > max_ep) return -1;
            int eidx = std::upper_bound(taps.begin(), taps.end(), sp, 
                [](int p1, const std::pair<int, int>& p2) {
                    return p1 < p2.first;
                }
            ) - taps.begin();
            int end_val = taps[eidx - 1].second;
            if (tap_ep < 0) {
                tap_ep = end_val;
                ++ result;
                if (end_val >= n) return result;
            } else if (sp > tap_ep) {
                tap_ep = max_ep;
                ++ result;
            }
            if (end_val > max_ep) {
                if (end_val >= n) return result + 1;
                max_ep = end_val;
            }
            idx = eidx;
        }
        return -1;
    }
};

int main(int argc, char** argv) {
    Solution sol;
    std::vector<int> taps = {0,3,3,2,2,4,2,1,5,1,0,1,2,3,0,3,1,1};
    int res = sol.minTaps(17, taps);
    printf("%d\n", res);
    return 0;
}