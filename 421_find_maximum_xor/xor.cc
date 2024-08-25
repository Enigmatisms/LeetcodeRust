#include <unordered_set>
#include <vector>
#include <iostream>

/**
 * 有些中等题... 真不配叫中等题... 半天一点思路都没有，有些困难题则一下就解决了... 
 * 本题利用了 XOR 不进位, localized 的特性以及 XOR 的计算性质，非常巧妙。倒序输出：
 *      每次确定本位是否可以取1。比如先确定最高位是否可取1，再次高，再... 确定高位是否可取1时
 *      与低位无关，所以可以仅使用高位进行运算。因为我们希望结果越大越好，每次就用最大的结果试
 *      看数组种是是否有数字（的高位部分）可以组成希望的结果。如果有：则通过XOR运算必能在
 *      hash表种找到成对的结果
 * runtime: 33.73% (很拉了，估计比较快的都是字典树版本)
 * memory： 19.1%
 */

constexpr int max_index = 30;

class Solution {
public:
    int findMaximumXOR(const std::vector<int>& nums) const {
        int result = 0;
        for (int k = max_index; k >= 0; k--) {
            std::unordered_set<int> set;
            // get the prefix of the numbers
            for (int v: nums) {
                set.insert(v >> k);
            }
            // set the highest bit to 1, and check if we can get it with all the prefixes.
            int candidate = (result << 1) + 1;
            bool can_set_1 = false;
            for (int v: set) {
                if (set.count(v ^ candidate)) {
                    can_set_1 = true;
                    break;
                }
            }
            if (can_set_1)
                result = candidate;
            else
                result = candidate - 1;
        }
        return result;
    }
};

int main() {
    std::vector<int> inputs1{14,70,53,83,49,91,36,80,92,51,66,70};
    std::vector<int> inputs2{3,10,5,25,2,8};
    std::vector<int> inputs3{1};
    Solution sol;
    printf("Result: %d\n", sol.findMaximumXOR(inputs1));
    printf("Result: %d\n", sol.findMaximumXOR(inputs2));
    printf("Result: %d\n", sol.findMaximumXOR(inputs3));
    return 0;
}