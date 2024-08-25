#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/**
 * 感觉这道题的做法是维护一个队列，因为我们知道
 * 可以组成被25整除的数字只有 0, 2, 5, 7 四个
 * 并且组合一定是 00, 25, 50, 75 四种
 * 
 * 这道题都要想那么久真是垃圾啊，没有意识到要从后面开始
 * 一直在想怎么 DP
 * 傻逼一个
 * runtime: 100.00%
 * memory:  29.17%
 */
class Solution {
public:
    int minimumOperations(string num) {
        int size = num.length(), zero_pos = -1, five_pos = -1;
        for (int i = size - 1; i >= 0; i--) {
            int v = num[i];
            if (v == '0') {       // 遇到零立刻记录，此后如果遇到 5 或者 0，那么就得到了一种结果
                if (zero_pos >= 0) {        // 找到两个0
                    // size - zero_pos - 1 代表的是从前面一个0到末尾需要删除的数字个数
                    // zero_pos - i - 1 代表的是从上一个 0 到这个 0 之间需要删除的个数
                    // 相加 size - i - 2
                    return size - i - 2;
                } 
                zero_pos = i;
            } else if (v == '5') {
                if (zero_pos >= 0) {        // 找到50
                    return size - i - 2;
                }
                if (five_pos < 0) five_pos = i;
            } else if (v == '2' || v == '7') {
                if (five_pos < 0) continue;
                return size - i - 2;
            }
        }
        return size - (zero_pos >= 0);          // 如果有 0, 0 不用删
    }
};

int main(int argc, char** argv) {
    Solution sol;

    return 0;
}