#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

/**
 * 
 * 一开始写的是O(n^2)
 * runtime: 
 * memory:  
 */
class Solution {
public:
    int longestSubsequence2(vector<int>& arr, int difference) {
        std::unordered_map<int, int> map;
        int result = 0;
        for (int v: arr) {
            map[v] = map[v - difference] + 1;       // 很好理解
            result = std::max(map[v], result);
        }
        return result;
    }

    int longestSubsequence2(vector<int>& arr, int difference) {
        int arr_len = static_cast<int>(arr.size());
        std::vector<int> dp(arr_len);
        dp.front() = 1;
        for (int i = 1; i < arr_len; i++) {
            int cur_diff = arr[i] - difference, max_val = 1;
            for (int j = 0; j < i; j++) {
                if (cur_diff == arr[j]) {
                    if (dp[j] >= max_val)
                        max_val = dp[j] + 1;
                }
            }
            dp[i] = max_val;
        }
        return *std::max_element(dp.begin(), dp.end());
    }
};

int main(int argc, char** argv) {
    Solution sol;

    return 0;
}