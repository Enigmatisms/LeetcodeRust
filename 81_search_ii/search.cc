#include <vector>
#include <iostream>
#include <algorithm>

class Solution {
public:
    bool search(const std::vector<int>& nums, int target) const {
        if (nums.size() == 1) return (target == nums.front());
        int break_point = find_break_point(nums);
        if (target >= nums.front()) {
            return std::binary_search(nums.begin(), nums.begin() + break_point, target);
        } else {
            return std::binary_search(nums.begin() + break_point, nums.end(), target);
        }
    }

    int find_break_point(const std::vector<int>& nums) const {
        int sp = 0, ep = nums.size() - 1, mp = (sp + ep + 1) >> 1;
        while (ep - sp > 1) {
            int center_v = nums[mp];
            if (center_v > nums[sp]) {
                sp = mp;
            } else if (center_v < nums[sp]) {
                ep = mp;
            } else {
                
            }
            mp = (sp + ep) >> 1;
        }
        return ep;
    }
};

int main(int argc, char ** argv) {
    Solution sol;
    std::vector<int> rotate1{4,5,6,6,7,7,7,7,0,0,1,2,4,4};
    std::vector<int> rotate2{4,4,4,4,4,4,4,4};
    std::vector<int> rotate3{1, 0, 1, 1, 1};
    std::vector<int> rotate4{4, 3, 4};
    std::cout << sol.search(rotate1, 7) << std::endl;
    std::cout << sol.search(rotate1, -1) << std::endl;
    std::cout << sol.search(rotate1, 0) << std::endl;
    std::cout << sol.search(rotate1, 3) << std::endl;
    std::cout << sol.search(rotate2, 1) << std::endl;
    std::cout << sol.search(rotate2, 4) << std::endl;
    std::cout << sol.search(rotate3, 0) << std::endl;
    std::cout << sol.search(rotate4, 2) << std::endl;
    return 0;
}