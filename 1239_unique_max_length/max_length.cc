#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/**
 * runtime: 85.00%
 * memory:  75.83%
 */
class Solution {
public:
    int maxLength(vector<string>& arr) {
        std::vector<int> vals;
        vals.reserve(arr.size());
        std::vector<string> valid_str;
        for (const std::string& s: arr) {
            int val = 0;
            for (char v: s) {
                int probe = 1 << (v - 'a');
                if (probe & val) {
                    val = 0;
                    break;
                }
                val |= 1 << (v - 'a');
            }
            if (val) {
                vals.emplace_back(val);
                valid_str.emplace_back(s);
            }
        }
        return recursive_solve(valid_str, vals, 0, 0, 0);
    }

    int recursive_solve(
        const std::vector<string>& arr, const std::vector<int>& vals,
        int cur_val, int index, int cur_length
    ) const {
        if (index >= arr.size()) return cur_length;
        int max_length = cur_length, val = vals[index];
        if ((val & cur_val) == 0) {
            int length = cur_length + arr[index].size();
            max_length = std::max(recursive_solve(arr, vals, val | cur_val, index + 1, length), cur_length);
        } 
        max_length = std::max(recursive_solve(arr, vals, cur_val, index + 1, cur_length), max_length);
        return max_length;
    }
};

int main(int argc, char** argv) {
    Solution sol;

    return 0;
}