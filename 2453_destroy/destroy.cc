#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <unordered_map>
#include <queue>

using namespace std;

/**
 * 这道题可以认为是寻找等差数列 space 的最大长度（对应的起始元素）
 * 但注意... 一个位置可以存在好几个目标 有一个非常好想的方法
 * 这个题并不难，但容易处理上有问题，比如一开始我用的是 vector 结果爆了内存
 * runtime: 95.71%
 * memory:  38.57%
 */
class Solution {
public:
    int destroyTargets(vector<int>& nums, int space) {
        std::unordered_map<int, std::pair<int, int>> cnts;
        cnts.reserve(std::max(4lu, nums.size() >> 2));
        for (int num: nums) {
            int index = num % space;
            auto it = cnts.find(index);
            if (it != cnts.end()) {
                it->second.first ++;
                it->second.second = std::min(it->second.second, num);
            } else {
                cnts[index] = std::pair(1, num);
            }
        }
        int max_cnt = 0, min_num = 1e9 + 1;
        for (auto [_, pr]: cnts) {
            int cnt = pr.first;
            if (cnt > max_cnt) {
                max_cnt = cnt;
                min_num = pr.second;
            } else if (cnt == max_cnt) {
                min_num = std::min(min_num, pr.second);
            }
        }
        return min_num;
    }
};

int main(int argc, char** argv) {
    Solution sol;

    return 0;
}