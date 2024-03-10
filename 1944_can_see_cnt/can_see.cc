#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <unordered_map>
#include <unordered_set>

using namespace std;

/**
 * 思路能想到，就是实现起来有一丝麻烦
 * 很简单，我给这个方法起名叫做 compress 数组
 * 每次存的时候，都会把小于当前值的所有值删除再加入
 * 这样其实会使得 compress 数组是降序的，查找很方便
 * 删除操作是 O(1) 的 (不能一个一个 pop, 这样是 O(n))
 * 比我矮的都会被遮挡，所以在数组中，i, j (i < j) 位置中间一定是严格降序的
 * runtime: 91.53%
 * memory:  6.71%
 */
class Solution {
public:
    vector<int> canSeePersonsCount(vector<int>& heights) {
        int num_p = heights.size();
        std::vector<int> result(num_p, 0);
        std::vector<int> compress = {heights.back()};
        for (int i = num_p - 2; i >= 0; i--) {
            int cur_h = heights[i];
            int kill_zone = std::upper_bound(compress.crbegin(), compress.crend(), cur_h) - compress.crbegin();
            result[i] = std::min(kill_zone + 1, int(compress.size()));
            compress.erase(compress.end() - kill_zone, compress.end());
            compress.push_back(cur_h);
        }
        return result;
    }
};

int main(int argc, char** argv) {
    Solution sol;

    return 0;
}