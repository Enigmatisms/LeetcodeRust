#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <cstring>
#include <unordered_map>
#include <unordered_set>

using namespace std;

/**
 * 内存复杂度为 O(n), 计算复杂度为 O(n^2)... 这样的复杂度还是太高了
 * runtime:
 * memory:
 */
constexpr long long MOD_NUM = 1e9 + 7;
class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        int arr_length = static_cast<int>(arr.size());
        std::vector<long long> min_values(arr_length, 30000);
        long long result = arr.front();
        min_values.front() = result;
        for (int i = 1; i < arr_length; i++) {
            int cur_val = arr[i];
            result += static_cast<long long>(cur_val);
            // 这里可以用二分查找。显然 min_values 是一个有序数列升序
            auto it = std::lower_bound(min_values.begin(), min_values.begin() + i, cur_val);
            if (it != min_values.end()) {
                int diff_pos = it - min_values.begin();
                std::fill(it, min_values.begin() + i, cur_val);
                result += std::accumulate(min_values.begin(), it, 0ll);
                result += static_cast<long long>(cur_val) * static_cast<long long>(min_values.begin() + i - it);
            } else {
                result += std::accumulate(min_values.begin(), min_values.begin() + i, 0ll);
            }
            min_values[i] = cur_val;
        }
        if (result >= MOD_NUM)
            return static_cast<int>(result % MOD_NUM);
        return static_cast<int>(result);
    }

    int sumSubarrayMins_old(vector<int>& arr) {
        int arr_length = static_cast<int>(arr.size());
        std::vector<long long> min_values(arr_length, 30000);
        long long result = arr.front();
        min_values.front() = result;
        for (int i = 1; i < arr_length; i++) {
            int cur_val = arr[i];
            min_values[i] = cur_val;
            result += static_cast<long long>(cur_val);
            if (cur_val > min_values[i - 1]) {
                result += std::accumulate(min_values.begin(), min_values.begin() + i, 0ll);
                continue;
            }
            for (int j = 0; j < i; j++) {
                if (cur_val < min_values[j]) {
                    std::fill(min_values.begin() + j, min_values.begin() + i, cur_val);
                    result += static_cast<long long>(cur_val) * static_cast<long long>(i - j);
                    break;
                } else {
                    result += min_values[j];
                }
            }
        }
        if (result >= MOD_NUM)
            return static_cast<int>(result % MOD_NUM);
        return static_cast<int>(result);
    }
};

int main(int argc, char** argv) {
    Solution sol;

    return 0;
}