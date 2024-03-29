#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <unordered_map>
#include <unordered_set>

using namespace std;

/**
 * 这道题解答有问题吧
 * [30, 20, 30, 10, 40] 竟然返回 0? 
 * runtime:
 * memory:
 */
class Solution {
public:
    // 这是针对子序列的
    int findRainbow(vector<int>& nums) {
        std::array<int, 7> mods = {1, 0, 0, 0, 0, 0, 0};
        for (int num: nums) {
            int mod = num % 7;
            if (!mod) return 1;
            ++ mods[mod];
            if (mods[mod] >= 7) return 1;
        } 
        for (int cur_num = 1; cur_num <= 6; cur_num++) {
            const int max_use_num = std::min(mods[cur_num], 7);
            for (int use_num = 1, target = 7; use_num <= max_use_num; use_num++) {
                target -= cur_num;       // sum to 7
                if (target < 0) break;
                if (mods[target]) return 1;
            }
        }
        return 0;
    }

    // 针对子数组的就是 O(n^2) 暴力了 用前后缀优化很容易写出来
    int findRainbow_arr(vector<int>& nums) {
        std::array<int, 7> mods = {1, 0, 0, 0, 0, 0, 0};
        for (int num: nums) {
            int mod = num % 7;
            if (!mod) return 1;
            ++ mods[mod];
            if (mods[mod] >= 7) return 1;
        } 
        for (int cur_num = 1; cur_num <= 6; cur_num++) {
            const int max_use_num = std::min(mods[cur_num], 7);
            for (int use_num = 1, target = 7; use_num <= max_use_num; use_num++) {
                target -= cur_num;       // sum to 7
                if (target < 0) break;
                if (mods[target]) return 1;
            }
        }
        return 0;
    }
};

int main(int argc, char** argv) {
    std::vector<std::vector<int>> tests = {
        {30, 20, 30, 10, 40},
        {3, 1, 4},
        {4, 2, 3, 3, 3}
    };
    Solution sol;
    for (int i = 0; i < tests.size(); i++) {
        std::cout << sol.findRainbow(tests[i]) << std::endl;
    }

    return 0;
}