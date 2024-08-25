#include <vector>
#include <iostream>
#include <algorithm>

/**
 * 这题是中等题吗？一开始我想着用分治法，后面想到：如果分治的话，结果复杂度为 O(nlogn) 那为什么不排序呢?
 * runtime: 80.18%
 * memory: 19.6%
*/

class Solution {
using Array  = std::vector<int>;
using Arrays = std::vector<Array>;
public:
    // 我们是否可以使用分治法？ 为什么不排序？
    struct ArrayOrder {
        bool operator()(const Array& arr1, const Array& arr2) const {
            return arr1.front() < arr2.front();
        }
    };
    Arrays merge(Arrays& intervals) const {
        if (intervals.size() < 2) {
            return intervals;
        }
        Arrays result;
        result.reserve(intervals.size() >> 1);
        std::sort(intervals.begin(), intervals.end(), ArrayOrder());
        int start_idx = intervals.front().front(), end_idx = intervals.front().back();
        for (size_t i = 1; i < intervals.size(); i++) {
            const Array cur_arr = intervals[i];
            if (cur_arr.front() <= end_idx) {
                if (cur_arr.back() > end_idx) 
                    end_idx = cur_arr.back();
            } else {
                result.push_back({start_idx, end_idx});
                start_idx = cur_arr.front();
                end_idx = cur_arr.back();
            }
        }
        result.push_back({start_idx, end_idx});
        return result;
    }
};

int main() {
    Solution sol;
    std::vector<std::vector<int>> testing = {{1, 3}, {5, 9}, {2, 6}, {10, 14}, {3, 5}, {6, 10}};
    auto result = sol.merge(testing);
    for (const auto& arr: result) {
        printf("(%d, %d)\n", arr.front(), arr.back());
    }
    return 0;
}