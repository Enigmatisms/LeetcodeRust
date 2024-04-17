#include <iostream>
#include <vector>
#include <algorithm>
#include "../ListNode.hpp"

using namespace std;

/**
 * 一次扫描，并且不使用额外的空间
 * 能不能记录一个恰好相差距离为 n 的指针？可以，双指针嘛
 * 
 * 是一遍遍历... 比较快（但实际上双指针走了两次）
 * runtime: 67.41%
 * memory:  75.77%
 */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode temp(0, head);
        ListNode *ptr_back = head, *ptr_front = &temp;
        for (int i = 0; i < n; i++)
            ptr_back = ptr_back->next;
        while (ptr_back) {
            ptr_back = ptr_back->next;
            ptr_front = ptr_front->next;
        }
        if (ptr_front == &temp) {
            return head->next;
        } else {
            ptr_front->next = ptr_front->next->next;
        }
        return head;
    }
};

int main(int argc, char** argv) {
    Solution sol;

    return 0;
}