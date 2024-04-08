#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

/**
 * 这道题的思路，看似很简单
 * (1) 首先排序，排序之后，看最长连续的数组有多长
 * (2) 此后，连续数组两端之外可能还存在不连续（但内部可能连续，可能不连续的）
 * 所以此时就是滑动窗口，看每一次 end 滑动到有值的位置时，窗口内部有多少空缺的位置
 * 每次移动需要花 O(logn) 复杂度查起始位置
 * 复杂度应该是 O(n logn)
 * 这道题... 怎么说呢，我思路基本没问题吧，但是复杂度表现太差了
 * 哇，但是... 和答案一模一样
 * runtime: 14.29%
 * memory:  5.36%
*/

class Solution {
public:
    int minOperations(vector<int>& nums) {
        int num_len = nums.size();
        if (num_len == 1) return 0;
        std::vector<int> new_vec;
        {
            std::set<int> sorted(nums.begin(), nums.end());
            new_vec.resize(sorted.size());
            new_vec.assign(sorted.begin(), sorted.end());
        }
        int sorted_size = new_vec.size(),
            end_digit = new_vec[0] + num_len - 1,
            num_consecutive = std::upper_bound(new_vec.begin(), new_vec.end(), end_digit) - new_vec.begin(),
            min_ops = num_len - num_consecutive;
        if (min_ops == 0) return 0;
        for (int i = num_consecutive; i < sorted_size; i++) {
            end_digit = new_vec[i];
            int start_digit = end_digit + 1 - num_len,
                start_index = std::lower_bound(new_vec.begin(), new_vec.end(), start_digit) - new_vec.begin();
            min_ops = std::min(min_ops, num_len - (i - start_index + 1));
        }
        return min_ops;
    }
};

int main() {
  Solution sol;
  std::vector<int> inputs = {1, 10, 100, 1000};
  sol.minOperations(inputs);
  return 0; 
}