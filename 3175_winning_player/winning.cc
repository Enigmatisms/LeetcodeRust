#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

/**
 * 必然不会是模拟。感觉像是单调栈，模拟就爆了，k数量级太大
 * 可以知道：最多一圈下来，就能确定，不会无限走：最大值必然能满足任何 k，只是可能不是最快的
 * 所以对于任意一个数，我们循环向后查k个值，遇到的第一个小于值就是被击败的，对应值算赢了一场
 * 这不是中等题吧，这个很简单啊
 * runtime: 79.95%
 * memory:  50.19%
 */
class Solution {
public:
    int findWinningPlayer(vector<int>& skills, int k) {
        int num_player = skills.size();
        int mvp_skill = skills[0], mvp = 0, consecutive = 0;
        for (int i = 1; i < num_player; i++) {
            if (consecutive >= k) {
                return mvp;
            }
            int cur_s = skills[i];
            if (mvp_skill > cur_s) {
                consecutive ++;
            } else {
                consecutive = 1;
                mvp_skill = cur_s;
                mvp = i;
            }
        }
        return mvp;
    }
};

int main(int argc, char** argv) {
    Solution sol;

    return 0;
}