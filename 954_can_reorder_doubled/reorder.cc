#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <queue>
#include <unordered_map>

using namespace std;

/**
 * 注意输入范围: 0 是可以直接被扔掉的，负数需要建立大顶堆，正数则小顶堆
 * 
 * O(nlogn) runtime: 99.48%
 * O(n)?     memory: 37.63%
 */
class Solution {
public:
    bool canReorderDoubled(vector<int>& arr) {
        std::unordered_map<int, int> mapping;
        std::priority_queue<int> max_heap_neg;
        std::priority_queue<int, std::vector<int>, std::greater<int>> min_heap_pos;
        for (int num: arr) {
            if (!num) continue;
            if (mapping.count(num)) 
                mapping[num] ++;
            else {
                mapping[num] = 1;
                if (num > 0)
                    min_heap_pos.emplace(num);
                else
                    max_heap_neg.emplace(num);
            }
        }
        while (min_heap_pos.empty() == false) {
            int val = min_heap_pos.top();
            min_heap_pos.pop();
            auto it = mapping.find(val);
            if (!it->second) continue;
            int doubled = it->first << 1;
            if (!mapping.count(doubled)) return false;
            int& num_doubled = mapping[doubled];
            num_doubled -= it->second;
            if (num_doubled < 0) return false;
        }

        while (max_heap_neg.empty() == false) {
            int val = max_heap_neg.top();
            max_heap_neg.pop();
            auto it = mapping.find(val);
            if (!it->second) continue;
            int doubled = it->first << 1;
            if (!mapping.count(doubled)) return false;
            int& num_doubled = mapping[doubled];
            num_doubled -= it->second;
            if (num_doubled < 0) return false;
        }
        return true;
    }
};

int main(int argc, char** argv) {
    Solution sol;

    return 0;
}