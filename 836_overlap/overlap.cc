#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <unordered_map>
#include <unordered_set>

using namespace std;

/**
 * runtime: 100.00%
 * memory:  31.08%
 */
class Solution {
public:
    bool isRectangleOverlap(vector<int>& rec1, vector<int>& rec2) {
        return overlap(rec1, rec2) || overlap(rec2, rec1);
    }

    bool overlap(vector<int>& one, vector<int>& other) {
        return other[0] < one[2] && other[1] < one[3] && other[2] > one[0] && other[3] > one[1];
    }
};

int main(int argc, char** argv) {
    Solution sol;

    return 0;
}