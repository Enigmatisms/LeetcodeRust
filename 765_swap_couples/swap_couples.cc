#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <unordered_map>
#include <unordered_set>

using namespace std;

/**
 * 本题也就是查环的数量，什么是环？
 * 可以串成首尾相连的就是环。不需要统计的环是：
 * 情侣(i, 1) -> 情侣(i, 2) -> 情侣(i, 1)
 * 而需要统计的是环中节点数量大于 2 的（只能是偶数）
 * 每一个环，需要通过环内情侣对数 - 1 ((n >> 1） - 1) 次操作
 * 把所有环加上就行
 * 可以 DFS 搜环
 * 我一开始想避免使用 unordered_set, 然后用了一个数组想不断交换元素到最后进行pop,结果逻辑出了点问题卡了我很长时间
 * runtime: 100.00%
 * memory:  10.88%
 */
class Solution {
public:
    int minSwapsCouples(vector<int>& row) {
        int num_people = row.size();
        std::vector<int> position(num_people);
        std::unordered_set<int> dup_row(row.begin(), row.end());
        for (int i = 0; i < num_people; i++)
            position[row[i]] = i;
        // look for circles
        int result = 0;
        while (dup_row.empty() == false) {
            int cur = *dup_row.begin(), ptr = cur, elem_cnt = 0;
            do {
                int cur_pos = position[ptr], nei_pos = cur_pos + 1 - ((cur_pos & 1) << 1);
                int neighbor = row[nei_pos], cur_cp  = ptr + 1 - ((ptr & 1) << 1);
                if (neighbor == ptr) {
                    dup_row.erase(ptr);
                    dup_row.erase(neighbor);
                    elem_cnt = 2;
                    break;
                }
                int neighbor_cp = neighbor + 1 - ((neighbor & 1) << 1);
                ptr = neighbor_cp;
                dup_row.erase(ptr);
                dup_row.erase(neighbor);
                elem_cnt += 2;
            } while (ptr != cur);
            result += (elem_cnt >> 1) - 1;
        }
        return result;
    }
};

int main(int argc, char** argv) {
    Solution sol;

    return 0;
}