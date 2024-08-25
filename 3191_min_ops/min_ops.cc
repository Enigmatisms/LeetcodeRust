/**
 * 
给你一个二进制数组 nums 。

你可以对数组执行以下操作 任意 次（也可以 0 次）：

选择数组中 任意连续 3 个元素，并将它们 全部反转 。
反转 一个元素指的是将它的值从 0 变 1 ，或者从 1 变 0 。

请你返回将 nums 中所有元素变为 1 的 最少 操作次数。如果无法全部变成 1 ，返回 -1 。

输入：nums = [0,1,1,1,0,0]
             [0,0,0,0,0,0]
             [1,1,1,0,0,0]
             [1,1,1,1,1,1]
输出：3

解释：
我们可以执行以下操作：

选择下标为 0 ，1 和 2 的元素并反转，得到 nums = [1,0,0,1,0,0] 。
选择下标为 1 ，2 和 3 的元素并反转，得到 nums = [1,1,1,0,0,0] 。
选择下标为 3 ，4 和 5 的元素并反转，得到 nums = [1,1,1,1,1,1] 。
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

/**
 * 看起来挺好玩的。首先，为什么是 3？换成别的可以吗？
 * 其次，如何证明某个策略一定最优？而且这个很贪心？
 * 弹性地修改：不影响已经修改过的，至少能保证同一处，我们手动判定是否需要修改的次数不超过 1
 * 也即每次修改尝试只讨论当前，i+1, i+2 三个位置，而不向前修改
 * 
 * 此方法是否是最优的？同一位置最多被修改三次，最多被主动修改一次
 * 感觉无法证明呢，只能说有个比较启发式的方法
 * 
 * runtime: 53.34%
 * memory:  12.08%
 */
class Solution {
public:
    int minOperations(vector<int>& nums) {
        int size = nums.size(), step = 0;
        for (int i = 0; i < size - 2; i++) {
            if (nums[i] == 1) continue;
            nums[i]      = 1;
            nums[i + 1] ^= 1;       // 异或1会导致为 0 的变1，为1的变 0
            nums[i + 2] ^= 1;       // 异或1会导致为 0 的变1，为1的变 0
            ++ step;
        }
        if (nums[size - 2] == 1 && nums[size - 1] == 1) return step;
        return -1;
    }
};
int main(int argc, char** argv) {
    Solution sol;

    return 0;
}