#include <vector>
#include <iostream>
/**
 * 注意审题
 * runtime: 100.00%
 * memory:  29.25%
 */
class Solution {
public:
    // 还要修改，第一次提交没有看到要修改数组内容... 我傻了
    int removeDuplicates(std::vector<int>& nums) const {
        bool is_duplicate = false;
        int dup_cnt = 0, last_num = nums.front();
        auto ptr = nums.begin() + 1;
        for (auto it = ptr; it != nums.end(); it++) {
            int val = *it;
            is_duplicate = (val == last_num);
            if (is_duplicate) {
                dup_cnt ++;
                if (dup_cnt == 1) {
                    *(ptr++) = last_num;
                }
            } else {
                dup_cnt  = 0;
                last_num = val;
                *(ptr++) = val;
            }
        }
        return ptr - nums.begin();
    }
};

int main() {
    Solution sol;
    std::vector<int> nums = {0, 0, 0, 1, 1, 1, 1, 2};
    int front = sol.removeDuplicates(nums);
    std::cout << front << std::endl;
    for (int i = 0; i < front; i++) {
        printf("%d, ", nums[i]);
    }
    printf("\n");
    return 0;
}