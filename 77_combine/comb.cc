#include <vector>
#include <iostream>

class Solution {
using Array = std::vector<int>;
using Arrays = std::vector<Array>;
public:
    Arrays combine(int n, int k) const {
        Array prefix;
        prefix.reserve(k);
        Arrays results;
        results.reserve(16);
        recursive_combination(prefix, results, n, k);
        return results;
    }

    void recursive_combination(Array& prefix, Arrays& results, int n, int k) const {
        if (k == 0) {
            results.push_back(prefix);
        } else {
            int start = prefix.empty() ? 1 : prefix.back() + 1;
            for (int i = start; i <= n; i++) {
                    prefix.push_back(i);
                    recursive_combination(prefix, results, n, k - 1);
                    prefix.pop_back();
            }
        }
    }
};

int main() {
    Solution sol;
    auto result = sol.combine(10, 4);
    return 0;
}