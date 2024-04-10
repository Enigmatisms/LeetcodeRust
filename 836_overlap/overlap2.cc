#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <unordered_map>
#include <unordered_set>

using namespace std;

/**
 * 根本不需要第一次实现的那么复杂
 * runtime: 100.00%
 * memory:  80.57%
 */
class Solution {
public:
    bool isRectangleOverlap(vector<int>& rec1, vector<int>& rec2) {
        bool down_bl = rec1[2] <= rec2[0] || rec1[3] <= rec2[1];      // 在左下
        bool up_tr   = rec1[0] >= rec2[2] || rec1[1] >= rec2[3];
        return !(down_bl || up_tr);
    }
};

int main(int argc, char** argv) {
    Solution sol;
    vector<int> rec1 = {0, 0, 2, 2};
    vector<int> rec2 = {1, 1, 3, 3};
    sol.isRectangleOverlap(rec1, rec2);
    return 0;
}