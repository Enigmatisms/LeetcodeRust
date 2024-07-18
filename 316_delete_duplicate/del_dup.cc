#include <array>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/**
 * 单调栈思想，总结一下是这样的：
 * 此栈在某种意义上是单调的（递增），这样可以保证大小关系
 * 对于此单调栈题：
 * - 1. 判定元素何时可以入栈：本题有两个条件（1）栈中不包含相同元素（2）入栈元素大于栈顶
 * - 2. 判定元素何时要出栈，本题为：（1）栈中不包含相同元素（2）栈顶元素大于入栈元素（3）**栈顶元素之后还存在**
 * 
 * 单调栈用来做什么？（1）处理大小关系（2）保证原始顺序
 * runtime: 100.00%
 * memory:  55.84%
 */
class Solution {
public:
    string removeDuplicateLetters(string s) {
        std::array<short, 26> cnts = {0,};
        uint32_t in_result = 0;
        // 统计出现了多少次
        for (char v: s)
            cnts[v - 'a'] ++;
        // 我们同时应该避免在出现无法pop时，前面已经有对应的元素的情况
        std::string result;
        for (char v: s) {
            int v_idx = v - 'a', check = 1 << v_idx;
            if (in_result & check) {
                -- cnts[v_idx];
                continue;                // 当前元素已经在栈中
            }
            while (!result.empty()) {
                char top = result.back();
                // 三个条件同时满足：（1）当前元素小于栈顶元素（2）当前元素不存在 (continue 处满了)（3）栈顶元素可以被 pop（即后面还有）
                int index = top - 'a';
                if (v < top && cnts[index]) {
                    result.pop_back();
                    in_result &= 0xffffffff - (1 << index);       // clear bit
                } else break;
            }
            if ((in_result & check) == 0) {           // whether char v is in the result, if not then we can push it in
                result.push_back(v);
                in_result |= check;
            }
            -- cnts[v_idx];
        }
        return result;
    }
};

int main(int argc, char** argv) {
    Solution sol;

    return 0;
}