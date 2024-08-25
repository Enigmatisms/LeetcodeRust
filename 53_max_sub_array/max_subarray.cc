#include <iostream>
#include <vector>
/**
 * runtime: 75.53%
 * memory:  52.23%
 * note that this is DP.
*/

class Solution {
public:
    /**
     * 要点记录: max_sum 用于记录最终结果，只大不小，不会清除
     * sum: 在为负数时很容易被清空，毕竟基本思想是: sum 为负说明前面可以丢弃，sum 小于当前的值则可以舍弃 sum 值，用当前值覆盖 sum
     * 本实现尚为 O(n) 版本。本题的思想是动态规划（但是我并没有用动态规划套路做，我... 暴力推逻辑推出来的）
     * 
    */
    int maxSubArray(const std::vector<int>& nums) const {
        int sum = -100000, max_sum = sum;
        int size = static_cast<int>(nums.size());
        for (int i = 0; i < size; i++) {
            int num = nums[i];
            if (max_sum >= 0) {
                if (sum < 0) {
                    if (num >= sum) {                       // this is crucial, very easy to miss
                        sum = 0;
                        if (num > max_sum) {
                            max_sum = num;
                        }
                    }
                    sum += num;
                } else {
                    sum += num;
                    if (num > 0 && sum > max_sum) {
                        max_sum = sum;
                    }
                }
            } else {
                if (num > max_sum) {
                    max_sum = num;
                    sum = num;
                }
            }
        }
        return max_sum;
    }
};

int main() {
    Solution sol;

    std::vector<int> test1{-2, 1, -3, 4, -1, 2, 1, -5, 4};
    std::vector<int> test2{8,-19, -1, 5,-4,20};
    std::vector<int> test3{-2, -1, -2, 0, -1, 1, 2, -1, 2};
    printf("Result for test1: %d\n", sol.maxSubArray(test1));
    printf("Result for test2: %d\n", sol.maxSubArray(test2));
    printf("Result for test3: %d\n", sol.maxSubArray(test3));
    return 0;
}