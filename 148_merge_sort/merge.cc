#include <iostream>
#include <vector>
#include <algorithm>
#include "../ListNode.hpp"

using namespace std;

/**
 * 
 * runtime: 89.02%
 * memory:  75.54%
 */
class Solution {
public:
    ListNode* sortList(ListNode* head) {
        if (!head || !head->next) return head;
        int length = 0;
        for (ListNode* ptr = head; ptr; ptr = ptr->next)
            length ++;
        return mergeSortList(head, length);
    }

    ListNode* mergeSortList(ListNode* head, int total_length) {
        if (total_length < 3) {
            if (total_length == 2) {
                if (head->val > head->next->val)
                    std::swap(head->val, head->next->val);
            }
            return head;
        }
        ListNode* back_start  = head;
        int front_length = total_length >> 1, back_length = total_length - front_length;
        for (int i = 0; i < front_length; i++)
            back_start = back_start->next;
        ListNode* front_node = mergeSortList(head, front_length);
        ListNode* back_node  = mergeSortList(back_start, back_length);
        return mergeTwoLists(front_node, back_node, front_length, back_length);
    }

    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2, int length1, int length2) {
        // 虚拟头节点，虚拟节点非常适合用于双向链表以及头节点随时需要改变的节点中
        ListNode dummy(0);
        ListNode *tail = &dummy;
        int cnt1 = 0, cnt2 = 0;
        while (cnt1 < length1 && cnt2 < length2) {
            if (l1->val < l2->val) {
                tail->next = l1;
                l1 = l1->next;
                cnt1 ++;
            } else {
                tail->next = l2;
                l2 = l2->next;
                cnt2 ++;
            }
            tail = tail->next;
        }
        int remaining = 0;
        if (cnt1 < length1) {
            tail->next = l1;
            remaining  = length1 - cnt1;
        } else {
            tail->next = l2;
            remaining  = length2 - cnt2;
        }
        for (int i = 0; i < remaining; i++)
            tail = tail->next;
        tail->next = nullptr;
        return dummy.next;
    }
};

int main(int argc, char** argv) {
    Solution sol;

    return 0;
}