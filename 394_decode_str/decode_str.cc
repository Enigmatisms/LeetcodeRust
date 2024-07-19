#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

/**
 * 本题需要使用栈，挺简单的，一遍过呢
 * runtime: 100.00%
 * memory:  82.96%
 */
class Solution {
public:
    string decodeString(string s) {
        std::string stack;
        std::vector<short> times;
        int slen = s.length();
        for (int i = 0; i < slen; i++) {
            char v = s[i];
            if (v == ']') {
                // 出栈开始，一直pop到最近的 [
                std::vector<char> temp;
                while (stack.empty() == false) {
                    char top = stack.back();
                    stack.pop_back();
                    if (top == '[') break;
                    temp.push_back(top);
                }
                short time = times.back();
                times.pop_back();
                
                for (int i = 0; i < time; i++) {        // 入栈 n 次
                    for (auto cr = temp.crbegin(); cr != temp.crend(); cr++) {
                        stack.push_back(*cr);
                    }
                }
            } else if (v >= '0' && v <= '9') { 
                // 遇到数字，直接处理完，数字不入栈
                short time = v - '0';
                for (int j = i + 1; ; j++) {
                    char cur = s[j];
                    if (cur == '[') {       // 推出前要正确设置主循环变量（j当前指向 [，但由于 i++，所以j要减一）
                        i = j - 1;
                        break;
                    }
                    time = time * 10 + (cur - '0');
                }
                times.push_back(time);
            } else {
                stack.push_back(v);
            }
        }
        return stack;
    }
};

int main(int argc, char** argv) {
    Solution sol;

    return 0;
}