#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

/**
 * 设 lis[i] 需要同时记录：长度与个数
 * lis[i] 只记录以 nums[i] 结尾的当前最长序列的个数
 * runtime: 92.33%
 * memory:  41.99%
 */
class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int num_len = static_cast<int>(nums.size());
        std::vector<std::pair<int, int>> lis(num_len);
        lis.front() = std::make_pair<int, int>(1, 1);
        for (int i = 1; i < num_len; i++) {
            int num_i = nums[i], max_len = 1, max_cnt = 1;
            for (int j = 0; j < i; j++) {
                if (nums[j] < num_i) {
                    int len_j = lis[j].first + 1;
                    if (len_j < max_len) continue;
                    else if (len_j > max_len) {
                        max_len = len_j;
                        max_cnt = lis[j].second;
                    } else {
                        max_cnt += lis[j].second;
                    }
                }
            }
            lis[i] = std::pair<int, int>(max_len, max_cnt);
        }
        int max_cnt = 0, max_len = 1;
        for (auto [len, cnt]: lis) {
            if (len > max_len) {
                max_len = len;
                max_cnt = cnt;
            } else if (len == max_len)
                max_cnt += cnt;
        }
        return max_cnt;
    }
};

int main(int argc, char** argv) {
    Solution sol;
    std::vector<int> numbers = {1,2,4,3,5,4,7,2};
    int res = sol.findNumberOfLIS(numbers);
    return 0;
}