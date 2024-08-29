#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/**
 * 
 * runtime: 50.56%
 * memory:  8.89%
 */
class Solution {
public:
    bool satisfiesConditions(vector<vector<int>>& grid) {
        int last_val = -1, rows = grid.size(), cols = grid[0].size();
        for (int c = 0; c < cols; c ++) {
            int current_val = grid[0][c];
            if (last_val >= 0 && current_val == last_val) return false;
            for (int r = 1; r < rows; r++) {
                if (grid[r][c] != current_val) return false;
            }
            last_val = current_val;
        }
        return true;
    }
};

int main(int argc, char** argv) {
    Solution sol;

    return 0;
}