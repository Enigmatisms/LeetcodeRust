#include <vector>
#include <iostream>

/**
 * Easy piece of cake
 * runtime:  100.00%
 * memory:   58.77%
 */

class Solution {
using Array = std::vector<int>;
using Arrays = std::vector<Array>;
public:
    Arrays subsets(Array& nums) const {
        Array prefix;
        prefix.reserve(nums.size());
        Arrays results;
        results.reserve(16);
        recursive_combination(nums, prefix, results, nums.cbegin());
        return results;
    }

    void recursive_combination(const Array& nums, Array& prefix, Arrays& results, Array::const_iterator start) const {
        results.push_back(prefix);
        if (start == nums.cend()) {
            return;
        } else {
            for (auto ptr = start; ptr != nums.cend(); ptr++) {
                prefix.push_back(*ptr);
                recursive_combination(nums, prefix, results, ptr + 1);
                prefix.pop_back();
            }
        }
    }
};

int main() {
    Solution sol;
    std::vector<int> test{1, 2, 3, 4};
    auto result = sol.subsets(test);
    for (auto res: result) {
        printf("[");
        for (int v: res) {
            printf("%d, ", v);
        }
        printf("]\n");
    }
    return 0;
}