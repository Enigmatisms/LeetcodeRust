#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/**
 * 就是个单调栈！
 * 再说一下单调栈的题（有什么特征）：
 * 前面的元素需要知道后面比当前元素更（大或小）的元素的性质
 * 处理大小关系的情况下，保持原始的顺序，一般都是单调栈
 * runtime: 66.48%
 * memory:  11.43%
 */
class Solution {
public:
    vector<int> dailyTemperatures(const vector<int>& temperatures) const {
        // 如果当前加入的温度大于栈顶，则栈顶出，出到当前加入的温度更小为止
        int temp_size = temperatures.size();
        std::vector<int> result(temp_size);
        std::vector<std::pair<int, int>> stack;
        stack.reserve(std::min(temp_size, 8));
        for (int i = 0; i < temp_size; i++) {
            int temp = temperatures[i];
            if (!stack.empty() && stack.back().first < temp) {
                do {
                    auto [smaller, idx] = stack.back();
                    if (smaller < temp) {
                        stack.pop_back();
                        result[idx] = i - idx;
                    } else break;
                } while (!stack.empty());
            }
            stack.emplace_back(temp, i);
        }
        return result;
    }
};

int main(int argc, char** argv) {
    Solution sol;

    return 0;
}