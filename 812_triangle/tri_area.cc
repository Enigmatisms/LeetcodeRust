#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <cmath>

using namespace std;

/**
 * 简单题... 要上暴力的大家都不敢动了
 * 三角形面积公式行列式版本：
 *       | x1 y1 1 |
 * 0.5 * | x2 y2 1 |
 *       | x3 y3 1 |
 * 注意结果可能要取绝对值
 * runtime:  90.91%
 * memory:   49.49%
 */
class Solution {
public:
    float triangleArea(int x1, int y1, int x2, int y2, int x3, int y3) {
        return 0.5f * fabsf(x1 * y2 + x2 * y3 + x3 * y1 - x1 * y3 - x2 * y1 - x3 * y2);
    }

    double largestTriangleArea(vector<vector<int>> & points) {
        int n = points.size();
        float ret = 0.0;
        for (int i = 0; i < n; i++) {
            int p1_x = points[i][0], p1_y = points[i][1];
            for (int j = i + 1; j < n; j++) {
                int p2_x = points[j][0], p2_y = points[j][1];
                for (int k = j + 1; k < n; k++) {
                    ret = max(ret, triangleArea(p1_x, p1_y, p2_x, p2_y, points[k][0], points[k][1]));
                }
            }
        }
        return ret;
    }
};

int main(int argc, char** argv) {
    Solution sol;

    return 0;
}