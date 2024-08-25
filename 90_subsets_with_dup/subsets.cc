#include <vector>
#include <unordered_map>

/**
 * Yes, this is so good. 使用【组合数】的思想
 * runtime: 100.00%
 * memory:  71.87%
 * 
*/

class Solution {
using Counter = std::unordered_map<int, int>;
using Set     = std::vector<int>;
using Sets    = std::vector<Set>;
public:
    Sets subsetsWithDup(const std::vector<int>& nums) const {
        Counter counter;
        int total_cnt = nums.size();
        for (int v: nums) {
            auto it = counter.find(v);
            if (it != counter.end())
                it->second ++;
            else
                counter[v] = 1;
        }
        Set num_vals, counting;
        for (auto [value, cnt_num]: counter) {
            num_vals.push_back(value);
            counting.push_back(int(cnt_num));
        }
        Set elements;
        Sets results;
        elements.reserve(nums.size());
        subset_recursive(num_vals, counting, elements, results, 0);
        return results;
    }

    void subset_recursive(const Set& num_vals, Set& counting, Set& elements, Sets& result, int index) const {
        if (index >= num_vals.size()) {
            result.push_back(elements);
            return;
        }
        int value = num_vals[index], max_num = counting[index], original_size = elements.size();
        for (int i = 0; i <= max_num; i++) {
            if (i > 0) {
                elements.push_back(value);
                counting[index] --;
            }
            subset_recursive(num_vals, counting, elements, result, index + 1);
        }
        elements.resize(original_size);         // reset
        counting[index] = max_num;              // reset
    }
};

int main() {
    Solution sol;
    auto results = sol.subsetsWithDup({1, 2, 2, 2, 3, 3, 4});
    for (const auto& arr: results) {
        printf("[");
        for (int v: arr) {
            printf("%d, ", v);
        }
        printf("]\n");
    }
    return 0;
}