#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/**
 * 
 * runtime: 77.99%
 * memory:  38.99%
 */
class Solution {
public:
    bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
        int c_x = p1[0] + p2[0] + p3[0] + p4[0], c_y = p1[1] + p2[1] + p3[1] + p4[1];
        std::vector<int64_t> xdiff = {4 * p1[0] - c_x, 4 * p2[0] - c_x, 4 * p3[0] - c_x, 4 * p4[0] - c_x};
        std::vector<int64_t> ydiff = {4 * p1[1] - c_y, 4 * p2[1] - c_y, 4 * p3[1] - c_y, 4 * p4[1] - c_y};
        for (int i = 0; i < 4; i++) {
            if (xdiff[i] == 0 && ydiff[i] == 0) return false;
        }
        int64_t non_zero_val = 0;
        for (int i = 0; i < 4; i++) {
            int64_t xi = xdiff[i], yi = ydiff[i];
            for (int j = i + 1; j < 4; j++) {
                int64_t dot_prod = xi * xdiff[j] + yi * ydiff[j]; 
                if (dot_prod == 0) continue;
                if (non_zero_val) {
                    if (dot_prod != non_zero_val) return false;
                } else {
                    non_zero_val = dot_prod;
                }
            }
        }
        return true;
    }
};

int main(int argc, char** argv) {
    Solution sol;

    return 0;
}