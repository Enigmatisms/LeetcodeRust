#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

int solve(std::vector<int>& nums, int num_elem, int num_odd) {
    int half_num_elem = num_elem >> 1;
    if (num_odd >= half_num_elem) {     // 奇偶相等或者奇数更多
        // 奇数可以直接乘以二变为偶数，所以只需要: (奇数 - 半数） 次操作
        return num_odd - half_num_elem;
    }
    // 如果偶数比奇数更多，偶数变奇数操作最少
    // 反正不要求速度，直接重新来算一遍
    std::vector<short> shift_num;           // 节省内存，否则可以int
    for (int num: nums) {
        if (num & 1) continue;
        for (int i = 1; i <= 31; i++) {
            num >>= 1;
            if (num & 1) {
                shift_num.push_back(i);
                break;
            }
        }
    }
    std::sort(shift_num.begin(), shift_num.end());
    int required = half_num_elem - num_odd;
    return std::accumulate(shift_num.begin(), shift_num.begin() + required, 0);
}

int main(int argc, char** argv) {
    int num_elem = 0;
    std::cin >> num_elem;
    std::vector<int> nums(num_elem);
    int num_odd = 0;        // 奇数个数
    for (int i = 0; i < num_elem; i++) {
        std::cin >> nums[i];
        num_odd += nums[i] & 1;
    }
    std::cout << solve(nums, num_elem, num_odd) << std::endl;
    return 0;
}