#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <unordered_map>
#include <unordered_set>

using namespace std;

/**
 * 这里我们使用最节省空间的动态规划
 * 动态规划的子问题比较容易导出：对于到达 (i, j) 可能有的走法
 * 它会等于到 (i - 1, j) 以及到 (i, j - 1) 可能走法数之和
 * 
 * 注意节省空间（状态空间的无后效性）：首先我们可以想到的是
 * 用 (n, 2) 数组来存储所需要的状态空间，这样的复杂度为 O(mn) (时间)， O(n) (空间)
 * 滚动数组则可以用 (N, 1)。做题的时候建议画图
 * 
 * 遇到这种题的时候，子问题的拆解很关键。我之前的思路是倒过来，斜着遍历，这巨容易出错，虽然很 intuitive
 * runtime: 100.00%
 * memory:  31.10%
 */
class Solution {
public:
    int uniquePaths(int m, int n) {
        if (m < n) std::swap(m, n);
        std::vector<int> reservior(n, 1);
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                reservior[j] += reservior[j - 1];
            }
        }
        return reservior.back();
    }
};

int main(int argc, char** argv) {
    Solution sol;

    return 0;
}