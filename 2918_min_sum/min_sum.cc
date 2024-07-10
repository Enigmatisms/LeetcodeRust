#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/**
 * 逻辑不难想，但结果感觉比较差啊
 * runtime: 18.71%
 * memory:  5.04%
 */
class Solution {
public:
    long long minSum(const vector<int>& nums1, const vector<int>& nums2) const {
        long long x = 0, y = 0, sumx = 0, sumy = 0;
        for (int n: nums1) {
            sumx += (long long)n;
            x    += n == 0;
        }
        for (int n: nums2) {
            sumy += (long long)n;
            y    += n == 0;
        }
        if (x > y) {
            std::swap(x, y);
            std::swap(sumx, sumy);
        }
        long long diff = sumy - sumx;
        if (y == 0 && diff != 0) return -1;
        if (x == 0 && -diff < y) return -1; 
        if (diff > 0) {
            return sumx + (x > y + diff ? x : y + diff);
        } else {
            return sumy + (y > x - diff ? y : x - diff);
        }
    }
};

int main(int argc, char** argv) {
    Solution sol;

    return 0;
}