#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/**
 * 用不着这么复杂... 在圆形的 bounding box 延展区域时，判定轴向距离与半径的关系
 * 分类讨论比较恶心，要写一大堆代码
 * runtime: 100.00%
 * memory:  37.31%
 */
class Solution {
public:
    bool checkOverlap(int radius, int xCenter, int yCenter, int x1, int y1, int x2, int y2) {
        int x = std::clamp(xCenter, x1, x2) - xCenter;
        int y = std::clamp(yCenter, y1, y2) - yCenter;
        return x * x + y * y <= radius * radius;
    }
};
int main(int argc, char** argv) {
    Solution sol;

    return 0;
}