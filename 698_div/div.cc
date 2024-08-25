#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <queue>
#include <unordered_map>

using namespace std;

/**
 * FIXME: 这是错误解法... 虽然秒做但是秒错
 * hard...
 * runtime:
 * memory:
 */
class Solution {
public:
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int sum = std::accumulate(nums.begin(), nums.end(), 0);
        if (sum % k || nums.size() < k) return false;
        int target = sum / k;
        std::deque<int> queue(nums.begin(), nums.end());
        std::sort(queue.begin(), queue.end());
        while (queue.empty() == false) {
            int back = queue.back();
            queue.pop_back();
            if (back > target) return false;
            else if (back < target) {
                do {
                    int front = queue.front();
                    queue.pop_front();
                    back += front;
                } while (back < target);
                if (back > target) return false;
            }
        }
        return true;
    }
};

int main(int argc, char** argv) {
    Solution sol;

    return 0;
}