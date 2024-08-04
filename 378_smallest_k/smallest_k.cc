#include <iostream>
#include <vector>
#include <queue>
using namespace std;

/**
 * 最暴力的方法显然就是拿出来 O(n^2) 用 kth_element 算法查
 * 这道题实际上可以用优先队列去解决
 * 实际上我们最多只会存储到 k 个，如果用优先队列：实际上等价于求第 k 小的元素
 * 所以只需要在这些元素中找到第 k 小。也即：我们先把每一行第一个元素放入
 * 此后，小顶堆开始pop：当前最小的元素的下一个加入
 * runtime: 21.43%
 * memory:  38.49%
*/
class Solution {
private:
    struct Element {
        int val;
        int row_col;

        int row() { return row_col >> 16; }
        int col() { return row_col & 0x0000ffff; }

        Element(int val_, int row_, int col_): val(val_), row_col((row_ << 16) + col_) {}

        bool operator > (const Element& other) const noexcept {
            return val > other.val;
        }
    };
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();
        std::priority_queue<Element, std::vector<Element>, std::greater<>> queue;
        for (int i = 0; i < n; i++)
            queue.emplace(matrix[i][0], i, 0);
        // 留下的第 k 个
        for (int i = 1; i < k; i++) {
            auto elem = queue.top();
            queue.pop();
            int row = elem.row(), col = elem.col();
            if (col < n - 1) {
                queue.emplace(matrix[row][col + 1], row, col + 1);
            }
        }
        return queue.top().val;
    }
};

int main() {
  Solution sol;
  
  return 0; 
}