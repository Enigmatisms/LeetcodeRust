#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <unordered_map>
#include <unordered_set>

using namespace std;

/**
 * 本题... 想清楚题目到底要我干什么，其实思路就很简单了
 * runtime: 95.65%
 * memory:  44.93%
 */
class Solution {
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {
        std::sort(arr.begin(), arr.end());
        int arr_len = arr.size(), cur_target = 2;
        for (int i = 1; i < arr_len; i++) {
            int v = arr[i];
            if (v < cur_target) continue;
            ++ cur_target;
        }
        return cur_target - 1;
    }
};

int main(int argc, char** argv) {
    Solution sol;

    return 0;
}