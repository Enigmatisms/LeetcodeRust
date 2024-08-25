#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 贪心就可以了
class Solution {
public:
    int num_warrior(std::vector<int>& w_stats, std::vector<int>& p_stats, int num_p) const {
        int num = 0, prev_index = 0;
        for (int warrior: w_stats) {
            if (prev_index >= num_p) break;
            int index = std::lower_bound(p_stats.begin() + prev_index, p_stats.end(), warrior) - p_stats.begin();
            if (index >= num_p) break;
            prev_index = index + 1;
            ++ num;
        }
        return num;
    }
};

int main() {
    Solution sol;
    int num_w = 0, num_p = 0;     // warrior and potion
    std::cin >> num_w >> num_p;
    
    std::vector<int> w_stats(num_w), p_stats(num_p);
    for (int i = 0; i < num_w; i++) 
        std::cin >> w_stats[i];
    for (int i = 0; i < num_p; i++) 
        std::cin >> p_stats[i];
    std::sort(w_stats.begin(), w_stats.end());
    std::sort(p_stats.begin(), p_stats.end());
    std::cout << sol.num_warrior(w_stats, p_stats, num_p) << std::endl;
    return 0; 
}