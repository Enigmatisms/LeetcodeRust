#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/**
 * 这tm是快乐数？痛苦数。想了半天妙法，最后无奈唉还是哈希表吧
 * 想到诶哈希表还带循环... 这不就tm是一个傻逼链表循环问题么
 * 双指针就行...
 * 还简单题...
 * runtime: 100.00%
 * memory:  38.51%
 */
class Solution {
public:
    bool isHappy(int n) {
        int fast_eval = n, slow_eval = n;
        do {
            fast_eval = break_down(fast_eval);
            if (fast_eval == 1) return true;
            fast_eval = break_down(fast_eval);
            if (fast_eval == 1) return true;
            slow_eval = break_down(slow_eval);
        } while (fast_eval != slow_eval);
        return false;
    }

    int break_down(int n) {
        int result = 0;
        while (n) {
            int val = n % 10;
            result += val * val;
            n /= 10;
        }
        return result;
    }
};

int main(int argc, char** argv) {
    Solution sol;

    return 0;
}