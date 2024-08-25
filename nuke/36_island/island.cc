#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <unordered_map>
#include <unordered_set>

using namespace std;

/**
 * runtime:
 * memory:
 */
class Solution {
public:
    int solve(vector<vector<char> >& grid) {
        int num_row = grid.size(), num_col = grid[0].size(), result = 0;
        for (int i = 0; i < num_row; i++) {
            for (int j = 0; j < num_col; j++) {
                if (grid[i][j] == '1') {
                    ++ result;
                    std::vector<std::pair<int, int>> stack;
                    stack.emplace_back(i, j);
                    while (stack.empty() == false) {
                        auto [pr, pc] = stack.back();
                        stack.pop_back();
                        grid[pr][pc] = '0';
                        if (pr > 0 && grid[pr - 1][pc] == '1') 
                            stack.emplace_back(pr - 1, pc);
                        if (pc > 0 && grid[pr][pc - 1] == '1') 
                            stack.emplace_back(pr, pc - 1);
                        if (pr + 1 < num_row && grid[pr + 1][pc] == '1') 
                            stack.emplace_back(pr + 1, pc);
                        if (pc + 1 < num_col && grid[pr][pc + 1] == '1') 
                            stack.emplace_back(pr, pc + 1);
                    }
                }
            }
        }
        return result;
    }
};

int main(int argc, char** argv) {
    Solution sol;

    return 0;
}