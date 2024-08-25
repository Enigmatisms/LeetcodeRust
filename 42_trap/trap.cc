#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <unordered_map>
#include <unordered_set>

using namespace std;

/**
 * 这道题与 11 很像。并且一定要画图理解！
 * 本题说是还有更好的双指针做法（空间常数复杂度）... 我真想不到了
 * 本题 O(n) 时间与空间
 * runtime: 94.56%
 * memory:  25.23%
 */
class Solution {
public:
    // 双数组做法原始
    int trap(vector<int>& height) {
        int num_buckets = static_cast<int>(height.size());
        std::vector<int> front_height(num_buckets, height.front()), back_height(num_buckets, height.back());
        for (int i = 1; i < num_buckets; i++)
            front_height[i] = std::max(front_height[i - 1], height[i]);
        for (int i = 1; i < num_buckets; i++)
            back_height[num_buckets - 1 - i] = std::max(back_height[num_buckets - i], height[num_buckets - 1 - i]);
        int capacity = 0;
        for (int i = 0; i < num_buckets; i++)
            capacity += std::min(front_height[i], back_height[i]) - height[i];
        return capacity;
    }

    // 双数组做法升级 (单数组)
    int trap(vector<int>& height) {
        int num_buckets = static_cast<int>(height.size()), capacity = -height.front();
        std::vector<int> front_height(num_buckets, height.front());
        for (int i = 1; i < num_buckets; i++) {
            int cur_height = height[i];
            capacity -= cur_height;
            front_height[i] = std::max(front_height[i - 1], cur_height);
        }
        int back_max = 0;
        for (int i = 0; i < num_buckets; i++) {
            if (height[num_buckets - 1 - i] > back_max)
                back_max = height[num_buckets - 1 - i];
            capacity += std::min(
                back_max, front_height[num_buckets - 1 - i]
            );
        }
        return capacity;
    }
};

int main(int argc, char** argv) {
    Solution sol;

    return 0;
}