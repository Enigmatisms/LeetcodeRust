#include <iostream>
#include <vector>

/**
 * 一种新型的二分查找思路：对目标进行二分查找。不断判断当前的目标N是否是可以达到的
 * 如果可以则下界变大。如果不可以则上界变小。
 * runtime: 53.70%
 * memory:  5.09%   (?为什么这么垃圾)
*/
#define LONG(x) static_cast<long>(x)
class Solution {
public:
    int maxNumberOfAlloys(
        int n, int k, int budget, 
        std::vector<std::vector<int>>& composition, 
        std::vector<int>& stock, 
        std::vector<int>& cost) {
        int lower_n = 0, upper_n = 2e8 + 1, mid_n = 0;
        do {    
            mid_n = (lower_n + upper_n) >> 1;
            bool find_smaller = false;
            for (int m_id = 0; m_id < k; m_id ++) {     // machine
                long e_cost = 0;
                const auto comp_mi = composition[m_id];
                for (int c_id = 0; c_id < n; c_id++) {  // component
                    e_cost += LONG(cost[c_id]) * (std::max(LONG(mid_n) * LONG(comp_mi[c_id]) - LONG(stock[c_id]), 0l));
                    if (e_cost > budget) break;
                }
                if (e_cost <= budget) {
                    find_smaller = true;
                    lower_n = mid_n;
                    if (upper_n - 1 <= lower_n)
                        return mid_n;
                    break;
                }
            }
            if (!find_smaller) {
                upper_n = mid_n;
                if (upper_n - 1 <= lower_n)
                    return mid_n - 1;
            }
        } while (true);
        return mid_n;
    }
};

int main() {
  Solution sol;
  
  return 0; 
}