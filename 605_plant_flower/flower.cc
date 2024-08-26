#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/**
 * 这题比 2390 难多了好吧，虽然也很简单
 * runtime: 38.64%
 * memory:  48.36%
 */
class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        // 我们就疯狂模拟？
        int plant_size = flowerbed.size();
        for (int i = 0; i < plant_size; i++) {
            int plant = flowerbed[i];
            if (plant == 1) {
                i = i + 1;
                continue;
            }
            bool plant_next = i + 1 < plant_size ? flowerbed[i + 1] == 0 : true;
            // 单看下一个是否是空，空就可种
            if (plant_next) {   // 空，可种
                n -= 1;
                i = i + 1;      // i + 1 是空的
                if (n <= 0) break;
            } else {
                i = i + 2;      // 不空，跳两格
            }
        }
        return n <= 0;
    }
};

int main(int argc, char** argv) {
    Solution sol;

    return 0;
}