#include <vector>
#include <iostream>
#include <algorithm>

/**
 * 这道题也很简单，就是我个人非常讨厌处理下标相关的问题(insert 重新计算位置)，大多数人觉得很简单的这种事情我觉得很绕
 * runtime:  97.95%
 * memory: 23.4%
*/

class Solution {
using Array  = std::vector<int>;
using Arrays = std::vector<Array>;
public:
    struct ArrayOrder {
        bool operator()(const Array& arr1, const Array& arr2) const {
            // Note this!!!!!! arr.back() and arr2.front()
            // 这里我的逻辑是找到 new_interval 下界所小于的区间上界位置，不能直接 arr1.front() < arr2.front()
            return arr1.back() < arr2.front();
        }
    };
    Arrays insert(Arrays& intervals, const Array& new_interval) const {
        size_t diff = std::lower_bound(intervals.begin(), intervals.end(), new_interval, ArrayOrder()) - intervals.begin();
        if (diff == intervals.size()) {
            intervals.push_back(new_interval);
            return intervals;
        }
        const Array& match_1st = intervals[diff];
        if (new_interval.back() < match_1st.front()) {
            intervals.insert(intervals.begin() + diff, new_interval);
            return intervals;
        }
        int start_idx = std::min(match_1st.front(), new_interval.front());
        int end_idx   = std::max(match_1st.back(), new_interval.back());
        size_t end_pos = diff + 1;
        for (; end_pos < intervals.size(); end_pos++) {
            const Array& arr = intervals[end_pos];
            if (arr.front() <= end_idx) {
                if (arr.back() > end_idx)
                    end_idx = arr.back();
            } else {
                break;
            }
        }
        intervals[diff] = {start_idx, end_idx};
        size_t len = end_pos - diff - 1, max_size = intervals.size() - len;
        for (size_t i = diff + 1; i < max_size; i++) {
            intervals[i] = intervals[i + len];
        }
        intervals.resize(max_size);
        return intervals;
    }
};

int main() {

    Solution sol;
    std::vector<std::vector<int>> testing = {{1,2}, {3,5}, {6,7}, {8,10}, {12,16}};
    auto result = sol.insert(testing, {4, 8});
    
    for (const auto& arr: testing) {
        printf("{%d, %d}\n", arr.front(), arr.back());
    }
    return 0;
    
}