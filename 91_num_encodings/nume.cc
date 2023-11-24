#include <iostream>
#include <vector>

/**
 * 思路很有意思，值得回看。注意，直接使用递归去做是很容易想到的一种思路，但太暴力了。你会发现这种问题递归会带来非常多的重复计算
 * 举个例子: [x ... x x] | [y .... y]
 * 与       [x ... x] | [x] | [y .... y]，后续的 [y .... y] 使用的计算是一样的
 * 递归适合求解: 所有可能的结果，而计数问题一般可以有更简单的方法（递推公式）
 * runtime:  100.00%
 * memory:   33.63%
*/

class Solution {
public:
    int numDecodings(const std::string& s) const {
        // 这个思路很容易想到，但是有些边界条件我非常粗心，老想错。
        if (s.length() < 2)
            return s[0] > '0';
        char s0 = s[0], s1 = s[1];
        if (s0 == '0') return 0;
        else if (s1 == '0' && s0 > '2') return 0;
        int last_cnt = 1, this_cnt = int(s1 > '0') + ((s0 < '2') || (s0 == '2' && s1 <= '6'));
        printf("last:");
        for (int i = 2; i < s.length(); i++) {
            char cur_v = s[i], last_v = s[i - 1];
            int new_cnt = 0;
            if (cur_v > '0') {
                new_cnt = this_cnt;
            }
            if (last_v > '0') {
                if (last_v < '3') {
                    if (last_v < '2') new_cnt += last_cnt;
                    else if (last_v == '2' && cur_v <= '6') new_cnt += last_cnt;
                }
            }
            if (new_cnt == 0) return 0;
            last_cnt = this_cnt;
            this_cnt = new_cnt;
        }
        return this_cnt;
    }

    // this will take a long time (TLE), let's throw the recursive solution away
    int numDecodings_recursive(const std::string& s) const {
        return nume_recursive(s, s.length(), 0);
    }

    int nume_recursive(const std::string& s, int str_len, int index) const {
        if (s[index] == '0') return 0;
        if (index >= str_len) return 1;
        int result = 0;
        result += nume_recursive(s, str_len, index + 1);
        if (index < str_len - 1) {
            char first = s[index], second = s[index + 1];
            if (first >= '3') return result;
            if (first == '2' && second > '6') return result; 
            result += nume_recursive(s, str_len, index + 2);
        }
        return result;
    }
};

int main() {
    Solution sol;
    std::vector<std::string> tests{"226", "13456", "606", "1212", "121212121212121212121212121212121212121212121", "275", "273", "27", "611"};
    for (auto s: tests) {
        printf("%d\n", sol.numDecodings(s));
    }
    return 0;
}