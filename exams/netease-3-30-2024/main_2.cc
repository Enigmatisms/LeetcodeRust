#include <iostream>
#include <vector>

// 这题估计需要使用dp，dp的状态转移如下：
/**
 * 用 DP[i] 表示生成长度为 i 的字符串所需要的操作数
 * 那么我们考虑 DP[i] 怎么算出来的，首先 
 * i 为偶数：
 * - i 最后一次可以由全选，复制，粘贴来。于是实际等于 DP[i / 2] + 3
 * - i 最后一次可以有单选，复制，粘贴来。于是为 DP[i - 1] + 3 （重启）;
 * - 可以是复制一次连续粘贴来。需要对应长度 i % j 是 0，则我们
 * i 为奇数：奇数不能直接复制
 * - i 最后一次可以有单选，复制，粘贴来。于是为 DP[i - 1] + 3 （重启）;
 * - 可以是复制一次连续粘贴来。需要对应长度 i % j 是 0，则我们
 * 还有一种情况是可以两段拼接？
 */

void solve(int num, const std::vector<int>& results) {
    int min_len = std::min(num, 6);
    std::vector<int> dp(num + 1, 0);
    dp[1] = 3;
    for (int i = 2; i <= min_len; i++)
        dp[i] = i + 1;
    for (int i = 7; i <= num; i++) {
        int min_num = i + 1, half_i = i >> 1;               // 单选一次，复制一次，粘贴 i - 1 次（最暴力的方法，上界）
        bool is_even = (i & 1) == 0;
        if (is_even)
            min_num = std::min(dp[half_i] + 3, min_num);    // 完全复制
        for (int j = half_i - is_even; j >= 1; --j) {
            min_num = std::min(min_num, dp[j] + dp[i - j] + 1);
            if (i % j == 0) {
                min_num = std::min(min_num, dp[j] + 1 + i / j);
            }
        }
        dp[i] = min_num;
    }
    dp[1] = 0;
    for (int target: results) {
        std::cout << dp[target] << std::endl;
    }
}

int main(int argc, char** argv) {
    int num_emp = 0, max_val = 0;
    std::cin >> num_emp;
    std::cin.get();
    std::vector<int> results(num_emp, 0);
    for (int i = 0; i < num_emp; i++) {
        std::cin >> results[i];
        max_val = std::max(max_val, results[i]);
        std::cin.get();
    }
    solve(max_val, results);
    return 0;
}