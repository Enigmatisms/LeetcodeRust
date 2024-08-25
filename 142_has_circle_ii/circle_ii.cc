#include <iostream>
#include <vector>
#include <algorithm>
#include "../ListNode.hpp"
using namespace std;

/**
 * 本题是一个链表追及问题 解决此题最好画个图
 * 画了图以后，本题仍然可以让人想一下子（如果很久没有碰过类似的题的话）
 * 
 * 
 * 
 * 假设进入圈前那一段长度为 a。有两个指针，一个快（2倍速），一个慢（1倍速）。假设有圈的话两个指针必然会在某一步数时重合
 * 设重合位置为进入圈后的 b 位置。那么慢指针显然走了 a + b 步，而快指针走了 2(a + b) 步，但快指针走的步数同时可以被表示为
 * a + b + (圈数 - 1) * 圈长
 * 所以，等起来: 2(a + b) = a + b + (圈数 - 1) * 圈长，可以得到 a + b 是圈长的整数倍。
 * 
 * 关键的一步：我们知道快慢指针目前都停留在距离圈起点 b 的位置。但 b 目前未知。我们可以直接令快指针速度与慢指针一致，并且
 * *** 回到起点 ***。当 两个指针重新走过 a 步后，由于 a + b 是圈长的整数倍，慢指针必定在圈起始位置，而快指针（变慢后的）
 * 此时也走过了进入圈之前需要走的 a 步，也在起始位置。两指针重合！此时退出。
 * runtime:  97.5%
 * memory:   22.6%
 */
class Solution {
public:
    ListNode* detectCycle(ListNode *head) const noexcept {
        if (!head) return nullptr;
        ListNode *fast = head, *slow = head;
        do {
            fast = fast->next;
            if (!fast) return nullptr;
            fast = fast->next;
            if (!fast) return nullptr;
            slow = slow->next;
        } while (fast != slow);
        // now, fast == slow
        fast = head;
        while (fast != slow) {
            slow = slow->next;
            fast = fast->next;
        }
        return fast;
    }
};

int main(int argc, char** argv) {
    Solution sol;

    return 0;
}