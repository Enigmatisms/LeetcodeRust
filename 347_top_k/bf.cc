#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>

using namespace std;

/**
 * 暴力做法:
 * (1) map key value 统计出现频率，key 是出现次数，value 是出现的数字
 * (2) 需要额外一个数字到出现频率的映射，才能尽快找出数字在 map 中的位置
 * 
 * 结果发现答案更暴力（不需要想得那么复杂）
 * runtime: 77.42%
 * memory:  58.40%
 */
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        std::unordered_map<int, int> cnts;
        for (int num: nums)
            ++ cnts[num];
        std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<>> queue;
        for (auto [num, cnt]: cnts) {
            queue.emplace(cnt, num);
            if (queue.size() > k)
                queue.pop();
        }
        std::vector<int> result;
        result.reserve(k);
        while (queue.empty() == false) {
            result.push_back(queue.top().second);
            queue.pop();
        }
        return result;
    }
};

int main(int argc, char** argv) {
    Solution sol;

    return 0;
}