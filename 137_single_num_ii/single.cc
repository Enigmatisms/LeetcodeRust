#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/**
 * 使用倍数性质：将每一个数字按位展开。如果出现了三次，那么这一位取3模一定是0。
 * 则剩下所有数字中，所有出现了三次的数字，对应位之和的模3一定为0，余下的那一个就是出现一次
 * 数字对应的位
 * runtime: 100.0%
 * memory:  14.73%
 */
class Solution {
public:
    int singleNumber(const vector<int>& nums) const {
        int result = 0;
        for (int i = 0; i < 32; i++) {
            int extractor = 1 << i, temp = 0;
            for (int num: nums)
                temp += (num & extractor) >> i;
            result += (temp % 3) << i;
        }
        return result;
    }
};

int main(int argc, char** argv) {
    Solution sol;

    return 0;
}