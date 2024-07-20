#include <iostream>
#include <vector>
#include <algorithm>
#include <deque>

using namespace std;

/**
 * 思想很简单
 * runtime: 7.01% (时间为什么这么长？)
 * memory:  52.43%
 */
class Solution {
public:
    string predictPartyVictory(string senate) {
        std::deque<uint8_t> queue;
        for (char v: senate)
            queue.push_back(2 + (v == 'R'));          // bit 2 is 1: valid, bit 1 is 1: R
        while (true) {
            uint8_t top = queue.front();
            queue.pop_front();
            if (top < 2) continue;          // 失去权利
            top = top & 1;                  // 已经知道当前是有投票权的了
            bool find_disident = false;     // 如果 for 循环下来没有找到持不同政见的哥们，就宣布胜利
            for (uint8_t& senator: queue) {
                if (senator < 2) continue;              // 一位之前已经被打击过的，待会儿就要被丢出去的可怜参议员，不需要操作
                if ((senator & 1) == top) continue;     // 同党不需要操作，跳过
                senator -= 2;
                find_disident = true;
                break;
            }
            if (find_disident == false)
                return top ? "Radiant" : "Dire";
            queue.push_back(top + 2);       // 回到队尾，并重新赋予权利
        }
        return "Radiant";
    }
};

int main(int argc, char** argv) {
    Solution sol;
    sol.predictPartyVictory("RDD");
    return 0;
}