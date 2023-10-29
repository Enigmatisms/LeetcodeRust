#include <string>
#include <vector>
#include <iostream>

/**
 * 逻辑非常混乱，思路一下就想出来了，但是实现一直不对... 这就很菜了
 * 这道题要注意的是,我一开始想错了，认为是需要用 lower_bound 去剪枝，实际上是根据n走的。此题的思路是：
 * 由于长度为 n 的第k个排列长度为 n，所以每一位都需要判定当前 index k 在何位置。例如：n = 4, k = 9 (开始时需减一)
 *      则可知，第一位选取时，剩下三位一共6种排列方法，故 8 / 6 -> 1 (index), 可知开头为2,取模数 n = 3, k = 2
 *      第二位选取时，剩下两位共2两种排列方法，故 2 / 2 -> 1 (index), 继续取模
 * 一定是根据 【剩余位有多少种排列方法】确定当前 index
 * runtime: 100.00%
 * memory:  31.19%
 * 我的评价是：做题脑子不清醒。
*/

constexpr uint16_t factos[9] = {(uint16_t)0, (uint16_t)1, (uint16_t)2, (uint16_t)6, (uint16_t)24, (uint16_t)120, (uint16_t)720, (uint16_t)5040, (uint16_t)40320};
// constexpr int factos[9] = {0, 1, 2, 6, 24, 120, 720, 5040, 40320};

class Solution {
public:
    std::string getPermutation(int n, int k) const {
        std::string result(n, '0');
        std::vector<bool> flags(n, false);
        k --;
        for (int i = n - 1, j = 0; i > 0; i--, j++) {
            int sub_num = factos[i];
            int tar_pos = k / sub_num, valid_cnt = 0, pos = 0;
            for (pos = 0; pos < n; pos++) {
                if (flags[pos]) continue;
                if (valid_cnt == tar_pos) {
                    break;
                }
                valid_cnt ++;
            }
            flags[pos] = true;
            result[j] = char(49 + pos);
            k %= sub_num;
        }
        for (int i = 0; i < n; i++) {
            if (flags[i]) continue;
            result[n - 1] = char(49 + i);
            break;
        }
        return result;
    }
};

int main() {
    Solution sol;

    auto res = sol.getPermutation(9, 54494);
    std::cout << res << std::endl;
    return 0;
}