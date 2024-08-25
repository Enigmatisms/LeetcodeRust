#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/**
 * 原来有序就可拆
 * 原来无序则可拆的部分只有其中有序的部分
 * 分段后，前段最大值大于后段，则失败，所以判断某处是否可以分段
 * 前段最大值要小于等于后段最小值
 * 所以可以使用 prefix reduce 的方式求解 min/max
 * 我的评价是，这题就简单题水平...
 * runtime: 70.09%
 * memory:  28.50%
 */
class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int arr_len = arr.size();
        std::vector<int> mini_rev(arr.size()), maxi(arr.size());
        maxi[0] = arr[0];
        mini_rev.back() = arr.back();
        for (int i = 1; i < arr_len; i++) {
            int rev_idx = arr_len - i - 1;
            maxi[i] = std::max(arr[i], maxi[i - 1]);
            mini_rev[rev_idx] = std::min(arr[rev_idx], mini_rev[rev_idx + 1]);
        }
        int sec = 0;
        for (int i = 0; i < arr_len - 1; i++) {
            sec += maxi[i] <= mini_rev[i + 1];
        }
        return sec + 1;
    }
};

int main(int argc, char** argv) {
    Solution sol;

    return 0;
}