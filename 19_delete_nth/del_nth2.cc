#include <iostream>
#include <vector>
#include <algorithm>
#include "../ListNode.hpp"

using namespace std;

/**
 * 本题两趟扫描自然是简单的。一趟稍微难想一点。
 * 一趟.... 怎么定义一趟？假设这样：倒数第2个删掉，那么我们需要在主指针走3步后开始用第二个指针从开始走
 * runtime: 100.00% 更快了，但是思路估计没变
 * memory:  5.11%
 */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if (!head->next) return nullptr;
        ListNode dummy(-1, head);
        ListNode *trac_ptr = &dummy;
        for (int i = 0; i < n; i++)
            head = head->next;
        while (head) {
            head     = head->next;
            trac_ptr = trac_ptr->next;
        }        
        trac_ptr->next = trac_ptr->next->next;
        return dummy.next;
    }

    ListNode* removeNthFromBegin(ListNode* head, int n) {
        // 实现的是正数，不是倒数
        if (n == 1) return head->next;
        ListNode dummy(-1, head);
        ListNode *prev = &dummy;
        for (int i = 1; i < n; i++) {
            prev = prev->next;
        }
        prev->next = prev->next->next;
        return dummy.next;
    }
};

int main(int argc, char** argv) {
    Solution sol;

    return 0;
}