#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <cstring>
#include <unordered_set>

using namespace std;

/**
 * 自定义一个 sort 函数就好了，但 nth_element 貌似有坑
 * 我好好写 （strcmp）
 * runtime: 98.34%
 * memory:
 */
class Solution {
public:
    string kthLargestNumber(vector<string>& nums, int k) {
        auto num_comp = [](const std::string& n1, const std::string& n2) {
            return n1.length() == n2.length() ? n1 > n2 : n1.length() > n2.length();
        };
        std::nth_element(nums.begin(), nums.begin() + k - 1, nums.end(), num_comp);
        return *(nums.begin() + k - 1);
    }
};

int main(int argc, char** argv) {
    Solution sol;
    std::vector<std::string> nums = {"0","0","0","0","10"};
    auto res = sol.kthLargestNumber(nums, atoi(argv[1]));
    std::cout << atoi(argv[1]) << ": " << res << std::endl; 
    return 0;
}