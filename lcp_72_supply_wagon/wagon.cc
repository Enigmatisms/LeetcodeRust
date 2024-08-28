#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <list>

using namespace std;

/**
 * 这道题用链表做会好一些吧？链表项的合并不需要移动，而且本题也不需要随机访问
 * 
 * runtime: 74.60%
 * memory:  14.29%
 */
class Solution {
public:
    vector<int> supplyWagon(vector<int>& supplies) {
        int target_len = supplies.size() >> 1;
        std::list<int> link_list;
        for (int wagon: supplies) link_list.push_back(wagon);
        int num_merge = supplies.size() - target_len;
        
        for (int i = 0; i < num_merge; i++) {
            auto min_it = link_list.begin(), it = min_it;
            int min_val = 2000, cur_len = link_list.size(), val = *it, old_val = 0;
            for (int i = 1; i < cur_len; i++) {
                auto old_it = it;
                val -= old_val;
                old_val = *it;
                it ++;
                val += *it;
                if (val < min_val) {
                    min_it = old_it;
                    min_val = val;
                }
            }
            *min_it = min_val;
            min_it ++;
            link_list.erase(min_it);        // remove the next value since the value is moved to the previous one
        }
        std::vector<int> result;
        result.reserve(target_len);
        for (int v: link_list)
            result.push_back(v);
        return result;
    }

    // 操，没看到相邻这个要求
    vector<int> supplyWagon_all(vector<int>& supplies) {
        int target_len = supplies.size() >> 1;
        std::priority_queue<int, std::vector<int>, std::greater<>> min_heap;
        for (int wagon: supplies) min_heap.emplace(wagon);
        int num_merge = supplies.size() - target_len;
        #pragma unroll
        for (int i = 0; i < num_merge; i++) {
            int wg1 = min_heap.top();
            min_heap.pop();
            int wg2 = min_heap.top();
            min_heap.pop();
            min_heap.emplace(wg1 + wg2);
        }
        std::vector<int> result;
        result.reserve(target_len);
        while (!min_heap.empty()) {
            result.push_back(min_heap.top());
            min_heap.pop();
        }
        return result;
    }
};

int main(int argc, char** argv) {
    Solution sol;

    return 0;
}