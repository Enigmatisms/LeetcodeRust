#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/**
 * 我直接能想到的最简单方法（思路最简单），仍然是分区讨论。这道题实际上是有向距离场的应用
 * 但四个边角的判断属实复杂
 * 
 * 还是回顾之前的写法吧
 * clamp 一下，快速出解
 * 当圆心 x 轴坐标在矩形 x 轴范围内时，显然我们只需要判定 y 轴是否远离某条边界足够 radius 距离（相当于直接求某轴距离）
 * 同理 y 可得
 * 在内部时不用判定
 * 
 * 
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