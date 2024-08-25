#include <iostream>

/**
 * 流氓，不使用sqrt可以使用别的浮点计算公式...
 * runtime: 100.00%
 * memory:  19.57%
 */

constexpr int max_p = 46341;

class Solution {
public:
    // 二分法
    int mySqrt(int x) const {
        int sp = 0, ep = max_p;
        while (ep - sp > 1) {
            int mp = (ep + sp) >> 1;
            int m_power = mp * mp;
            if (m_power > x) {
                ep = mp;
            } else if (m_power < x) {
                sp = mp;
            } else {
                return mp;
            }
        }
        return sp;
    }
};

int main(int argc, char** argv) {
    Solution sol;
    int number = atoi(argv[1]);
    printf("res = %d\n", sol.mySqrt(number));
    return 0;
}