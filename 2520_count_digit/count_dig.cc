#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <unordered_map>
#include <unordered_set>

using namespace std;

/**
 * runtime: 100.00%
 * memory:  15.36%
 */
class Solution {
public:
    int countDigits(int num) {
        int now_num = num, cnt = 0;
        while (now_num) {
            int digit = now_num % 10;
            cnt += (num % digit == 0);
            now_num /= 10;
        }
        return cnt;
    }
};

int main(int argc, char** argv) {
    Solution sol;

    return 0;
}