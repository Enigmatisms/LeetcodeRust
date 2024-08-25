#include <vector>
#include <iostream>

/**
 * rumtime: 83.33%
 * memory:  74.65%
*/

class Solution {
public:
    // 我仍然不是很会建模 rolling vector，但本问题可以投机取巧...
    int minPathSum(std::vector<std::vector<int>>& grid) {
        int max_row = static_cast<int>(grid.size()), max_col = static_cast<int>(grid.front().size());
        int row = max_row - 1, col = max_col - 2;
        if (col < 0) {
            int sum = 0;
            for (const auto& arr: grid) {
                sum += arr.front();
            }
            return sum;
        }
        while (true) {
            for (int r = row, c = col; r >= 0 && c < max_col; r--, c++) {
                if (r == max_row - 1) {
                    grid[r][c] += grid[r][c + 1];
                } else {
                    if (c == max_col - 1) {
                        grid[r][c] += grid[r + 1][c];
                    } else {
                        grid[r][c] += std::min(grid[r + 1][c], grid[r][c + 1]);
                    }
                }
            }
            if (col > 0) {
                col --;
            } else {
                if (row == 0) {
                    break;
                }
                row --;
            }
        }
        return grid.front().front();
    }
};

int main() {
    Solution sol;
    std::vector<std::vector<int>> grid1{{1,3,1},{1,5,1},{4,2,1}};
    std::vector<std::vector<int>> grid2{{1,2,3},{4,5,6}};
    std::vector<std::vector<int>> grid3{{1},{1}};
    std::vector<std::vector<int>> grid4{{1, 1}};
    std::vector<std::vector<int>> grid5{{0}};
    int path_len1 = sol.minPathSum(grid1);
    int path_len2 = sol.minPathSum(grid2);
    int path_len3 = sol.minPathSum(grid3);
    int path_len4 = sol.minPathSum(grid4);
    int path_len5 = sol.minPathSum(grid5);
    printf("Path len: %d\n", path_len1);
    printf("Path len: %d\n", path_len2);
    printf("Path len: %d\n", path_len3);
    printf("Path len: %d\n", path_len4);
    printf("Path len: %d\n", path_len5);
    return 0;
}