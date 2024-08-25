#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <unordered_map>
#include <unordered_set>

using namespace std;

/**
 * 首先应该进行区间合并，这样就可以不用反复操作 s 中的元素了
 * 但很可惜 TLE. 这里我们学习一个新的知识叫做差分数组
 * 差分数组挺有趣的，可以有效缓解第一个二重for的计算burden
 * 
 * 差分数组常用在对某区间进行频繁修改的情况，学到了，好东西啊。
 * runtime: 97.54%
 * memory:  36.89%
 */
class Solution {
public:
    // 差分数组写法
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        int slen = s.length();
        std::vector<int> shift_num(slen, 0);
        for (const auto& shift: shifts) {
            int sp = shift[0], ep = shift[1], add = (shift[2] << 1) - 1;
            shift_num[sp] += add;
            if (ep + 1 < slen)
                shift_num[ep + 1] -= add;
        }
        std::partial_sum(shift_num.begin(), shift_num.end(), shift_num.begin());
        for (size_t i = 0; i < s.length(); i++) {
            int shift = shift_num[i] % 26;
            int v = s[i];
            v += shift;
            if (v < 'a')
                v += 26;
            else if (v > 'z')
                v -= 26;
            s[i] = static_cast<char>(v);
        }
        return s;
    }

    string shiftingLetters_bf(string s, vector<vector<int>>& shifts) {
        std::vector<int> shift_num(s.length(), 0);
        for (const auto& shift: shifts) {
            int sp = shift[0], ep = shift[1], add = shift[2];
            for (int i = sp; i <= ep; i++) {
                shift_num[i] += (add << 1) - 1;
            }
        }
        for (size_t i = 0; i < s.length(); i++) {
            int shift = shift_num[i] % 26;
            int v = s[i];
            v += shift;
            if (v < 'a')
                v += 26;
            else if (v > 'z')
                v -= 26;
            s[i] = static_cast<char>(v);
        }
        return s;
    }
};

int main(int argc, char** argv) {
    Solution sol;

    return 0;
}