#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/**
 * 这道题其实不太难，举个例子，首先我们需要知道数字总长
 * 比如 827 541 032 9, k = 3
 * 那么从高到低确定：8 我们可以尝试直接删，看是否接受，则判断下一个数字 2
 * 更小，说明 8 要删，继续走 7 不小于 2, 5 也不小于 2 说明从最顶部开始，如果连删3个数字都只等于 5，而最小的为 2
 * 说明我们应该用 2，删去 8，则 k = 2 继续，这可以递归了
 * 但上述方法还是会有重读的问题，先看看结果如何
 * 
 * 正确的，快速的思路是单调栈
 * 
 * runtime: 5.01% (这完全是暴力法) 
 * memory:  93.25% (但是空间复杂度控制的不错)
 */
class Solution {
public:
    string removeKdigits(string num, int k) {
        int length = num.length();
        std::string result;
        removeKdigitsRecursive(num, result, 0, k, length);
        if (result.empty()) 
            result.push_back('0');
        return result;
    }

    void removeKdigitsRecursive(const std::string& num, std::string& res, int index, int k, int length) {
        if (k == 0) {                           // nothing can be removed anymore
            auto suffix = num.substr(index);
            if (res.empty() && !suffix.empty()) {
                auto pos = std::min(suffix.find_first_not_of('0'), suffix.size());
                suffix = suffix.substr(pos);
            }
            res.append(suffix);
            return;
        }
        if (length - index <= k)                // all should be removed
            return;
        int min_index = 0;
        char min_val  = num[index];
        for (int i = 1; i <= k; i++) {
            char v = num[index + i];
            if (v < min_val) {
                min_val = v;
                min_index = i;
                if (min_val == '0') break;
            }
        }
        if (!res.empty() || min_val != '0')
            res.push_back(min_val);
        removeKdigitsRecursive(num, res, index + min_index + 1, k - min_index, length);
    }
};

int main(int argc, char** argv) {
    Solution sol;
    std::cout << sol.removeKdigits("1432219", 3) << std::endl;
    return 0;
}