#include <vector>
#include <iostream>
/**
 * Speed: 78.30%
 * Memory: 27.53%
*/

class Solution {
/**
 * 这是个 DP 问题吧,我总可以把问题拆成：是否能一步到达某个节点 -> 多个此类问题
 * this is so fucking easy, it took me less than 10min to complete
*/
public:
    bool canJump(const std::vector<int>& nums) const {
        int len_num = nums.size();
        if (len_num == 1) return true;
        int max_pos = len_num - 1;
        for (int i = max_pos - 1; i >= 0; i--) {
            int cur_step = nums[i];
            if (cur_step >= max_pos - i) {
                max_pos = i;
            }
        }
        return max_pos == 0;
    }
};

int main() {
    Solution sol;
    std::vector<int> test1{2,3,1,1,4};
    std::vector<int> test2{3,2,1,0,4};
    std::vector<int> test3{2, 0, 1, 1, 3, 0, 0, 2, 3, 3, 4, 1, 1, 0, 5, 1, 0, 1, 0, 2, 0, 0};
    printf("Can? %d\n", int(sol.canJump(test1)));
    printf("Can? %d\n", int(sol.canJump(test2)));
    printf("Can? %d\n", int(sol.canJump(test3)));
    return 0;
}