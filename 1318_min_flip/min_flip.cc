#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/**
 * straightforward
 * a or b，如果 c 某一位上是 0，则 a 和 b 可能最多需要转两位
 * 而 c 某一位上为 1 时，a 或 b 至多转一位，所以一位位查即可
 * 这不难，就是容易写错
 * 
 * runtime: 32.89%
 * memory:  11.85%
 */
class Solution {
public:
    int minFlips(int a, int b, int c) {
        int flip_cnt = 0;
        for (int i = 0, flag = 1; i < 32; i++, flag <<= 1) {
            bool a_set = (a & flag) > 0, b_set = (b & flag) > 0;
            if (c & flag) {     // c 对应位 set
                flip_cnt += !(a_set || b_set);         // 至多转1位，也即看是否存在非 0
            } else {            // c 对应位为 0
                flip_cnt += int(a_set) + int(b_set);      // 都要转为 0
            }
        }
        return flip_cnt;
    }
};

int main(int argc, char** argv) {
    Solution sol;

    return 0;
}