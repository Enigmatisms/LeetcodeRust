#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <unordered_map>
#include <unordered_set>

using namespace std;

/**
 * 主要看你能不能找到其中的规律：
 * 对于给定的起始i 与 末尾 j 两个板子（线），我们以起始i为例子(假设它更短)
 * 固定 i 不变，变j。由于 h[i] < h[j], 中间的其他选择都没有意义：
 * - 高度不会大于 h[i]，宽度不会大于 j - i。故如何需要找到比 (i, j) 确定的区域大的区域，必须
 * 重新选择 i (短边)
 * runtime: 98.44%
 * memory:  29.97%
 */
class Solution {
public:
    int maxArea(const vector<int>& height) const {
        int sptr = 0, eptr = static_cast<int>(height.size()) - 1, max_area = 0;
        while (sptr < eptr) {
            if (height[sptr] <= height[eptr]) {
                max_area = std::max(max_area, height[sptr] * (eptr - sptr));
                sptr ++;
            } else {
                max_area = std::max(max_area, height[eptr] * (eptr - sptr));
                eptr --;
            }
        }
        return max_area;
    }
};

int main(int argc, char** argv) {
    Solution sol;

    return 0;
}