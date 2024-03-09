#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <unordered_map>
#include <queue>

using namespace std;

/**
 * 前五分钟就有了一个我觉得很妙的思路，结果是错的... 笑死了
 * 要是面试碰到这种，顶级尴尬：先给面试官说我想出来了！然后发现思路是错的...
 * 而且允许有负数使得难度更大了
 * 这道题难度太大了... 我根本想不到这种解法... 啊 蠢
 * runtime:
 * memory:
 */
class Solution {
public:
    long long kSum(vector<int> &nums, int k) {
        int n = nums.size();
        long long total = 0;
        for (int &x : nums) {
            if (x >= 0) {
                total += x;
            } else {
                x = -x;
            }
        }
        sort(nums.begin(), nums.end());

        long long ret = 0;
        std::priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<>> pq;
        pq.push({nums[0], 0});
        for (int j = 2; j <= k; j++) {
            auto [t, i] = pq.top();
            pq.pop();
            ret = t;
            if (i == n - 1) {
                continue;
            }
            pq.push({t + nums[i + 1], i + 1});
            pq.push({t - nums[i] + nums[i + 1], i + 1});
        }
        return total - ret;
    }
};

int main(int argc, char** argv) {
    Solution sol;

    return 0;
}