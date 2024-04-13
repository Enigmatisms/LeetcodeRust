#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

class Solution {
public:
    int max_y_possible(std::vector<int>& cis, int n, int x) const {
        std::map<int, int> max_vals; 
        int last_max = cis[0];
        for (int i = x; i < last_max; i++)
            ++ max_vals[last_max - i];
        last_max -= x;
        if (last_max <= 0) return -1;
        for (int i = 1; i < n; i++) {
            int ci = cis[i], start_x = x;
            if (ci - x > last_max)
                start_x = ((ci - last_max + x - 1) / x) * x;
            else if (ci - x < last_max)
                last_max = ci - x;
            for (int i = start_x; i < ci; i += x) {
                ++ max_vals[ci - i];
            }
        }
        int result = -1;
        for (auto rit = max_vals.rbegin(); rit != max_vals.rend(); rit++) {
            int cnt = rit->second;
            if (cnt != n || rit->first == 0) continue;
            result = rit->first;
            break;
        }
        return result;
    }
};

int main() {
    Solution sol;
    int n = 0, x = 0;
    std::cin >> n >> x;
    std::vector<int> cis(n);
    for (int i = 0; i < n; i++) 
        std::cin >> cis[i];
    std::sort(cis.begin(), cis.end());
    std::cout << sol.max_y_possible(cis, n, x) << std::endl;
    return 0; 
}