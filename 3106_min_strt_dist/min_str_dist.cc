#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/**
 * 本问题返回的结果是：修改后，逐字符之间的距离的最小值之和要小于某个值，且新的字典序最小
 * 
 * 字典序最小，与距离和小于某个值之间存在冲突。比如距离中后的字母，比如 q （第17）
 * 转到 a 可以向后比（a 算是第27个字母，所以距离为 10），能不能转到，要看距离是否值得。
 * 显然：贪心，如果第一个能转 a，那么剩下的减就好。
 * 比较简单的一题，思路很简单，实现也很简单（就是我是递归的，但改 for 很简单，我一开始想的思路是递归，但应该 for 的，算了不改了）
 * 
 * 宗旨是尽量在保留更多 k 的情况下，让 s[index] 接近 'a'
 * 用 mod：一个字母到 a 的距离最大不可能超过 13，最远的字母为 n，距离 a 是 13
 * k 如果大于等于 13，任何一个字母可以直接上车，小于等于 n 则直接 k - (s[index] - 'a')，大于 n 则  k - 26 + (s[index] - 'a')
 * 如果 k 小于 13，当前不一定够到 'a'（视情况）：
 * 如果字母大于 n，那么我们看 26 - (s[index] - 'a') 与 k 的关系（前者表示与 'a' 的距离），如果 k 大于此值，向右走到 'a' 就好，小于则向左走完
 * 如果字母小于等于 n，那么直接向左走，不需要犹豫，走到 'a' clamp 掉就行
 * 
 * runtime: 37.67%
 * memory:  15.82%
 */
class Solution {
public:
    string getSmallestString(string s, int k) {
        stringModRecursive(s, 0, k);
        return s;
    }

    static void stringModRecursive(std::string& s, int index, int k) noexcept {
        if (k == 0 || index >= s.length()) return;
        char& cur_v = s[index];
        if (cur_v <= 'n') {
            int delta = std::min(k, cur_v - 'a');       // 最大不超过 k 步，但尽可能离 'a' 近
            cur_v -= delta;
            k     -= delta;
        } else {
            int dist_to_a = 26 - (cur_v - 'a');
            if (dist_to_a <= k) {
                cur_v = 'a';
                k -= dist_to_a;     // 向右走到 'a'
            } else {
                cur_v -= k;         // 向左走完 k
                k = 0;
            }
        }
        stringModRecursive(s, index + 1, k);
    }
};

int main(int argc, char** argv) {
    Solution sol;

    return 0;
}