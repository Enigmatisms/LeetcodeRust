#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/**
 * 注意运算可能超界！ A - B > 1 (A - B) 可能超界，但 A > B + 1 就不容易超界了
 * runtime: 100.00%
 * memory:  35.21%
 */
class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        if (nums.empty()) return {};
        std::vector<std::string> results;
        int last_num = nums.front();
        for (size_t i = 1; i < nums.size(); i++) {
            int cur_num = nums[i];
            if (cur_num > 1 + last_num) {
                results.push_back(std::to_string(last_num));
            } else {
                std::string s = std::to_string(last_num) + "->";
                for (i = i + 1; i < nums.size(); i++) {
                    last_num = cur_num;
                    cur_num = nums[i];
                    if (cur_num > last_num + 1) 
                        break;
                }
                if (cur_num > 1 + last_num)
                    s += std::to_string(last_num);
                else
                    s += std::to_string(cur_num);
                results.push_back(s);
                if (cur_num == last_num + 1)
                    return results;
            }
            last_num = cur_num;
        }
        results.push_back(std::to_string(last_num));
        return results;
    }
};

int main(int argc, char** argv) {
    Solution sol;

    return 0;
}