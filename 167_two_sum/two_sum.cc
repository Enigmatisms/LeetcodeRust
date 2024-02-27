#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/**
 * runtime: 98.83%
 * memory:  38.69%
 */
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        // 可以先二分再双指针？
        int sptr = 0, eptr = static_cast<int>(numbers.size()) - 1, mptr = 0;
        while (true) {
            mptr = (sptr + eptr) >> 1;
            int lval = numbers[sptr] + numbers[mptr];
            if (lval > target) {
                eptr = mptr;
                continue;
            } else if (lval == target) return {sptr + 1, mptr + 1};
            int rval = numbers[eptr] + numbers[mptr];
            if (rval < target) {
                sptr = mptr;
                continue;
            } else if (rval == target) return {mptr + 1, eptr + 1};
            break;
        }
        while (true) {
            int residual = target - numbers[eptr];
            for (;sptr < eptr; sptr ++) {
                int cur_val = numbers[sptr];
                if (cur_val == residual) return {sptr + 1, eptr + 1};
                else if (cur_val > residual) {
                    eptr --;
                    break;
                }
            }
        }
        return {sptr + 1, eptr + 1};
    }
};

int main(int argc, char** argv) {
    Solution sol;

    return 0;
}