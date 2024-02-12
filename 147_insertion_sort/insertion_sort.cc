#include <iostream>
#include <vector>
#include <algorithm>
#include "../ListNode.hpp"

using namespace std;

/**
 * 这道题... 逻辑死活写不对... 我真吐了，好多遍才过，思想很简单
 * 官方解的内存表现也不佳
 * runtime: 97.47%
 * memory:  16.45%
 */
class Solution {
public:
    ListNode* insertionSortList(ListNode* head) {
        if (!head->next) return head;
        ListNode *pre_ptr = head, *cur_ptr = head->next, *cur_head = head;
        while (cur_ptr) {
            if (cur_head->val > cur_ptr->val) {
                pre_ptr->next = cur_ptr->next;
                cur_ptr->next = cur_head;
                cur_head = cur_ptr;
                cur_ptr  = pre_ptr->next;
                continue;
            }
            ListNode *track = cur_head;
            bool update_ptr = false;
            while (track->next->val <= cur_ptr->val) {
                if (track->next == cur_ptr) {
                    update_ptr = true;
                    break;
                }
                track = track->next;
            }
            if (update_ptr) {
                do {
                    pre_ptr = cur_ptr;
                    cur_ptr = cur_ptr->next;
                    track = track->next;
                } while (cur_ptr && track->val <= cur_ptr->val);
                continue;
            }
            pre_ptr->next = cur_ptr->next;
            cur_ptr->next = track->next;
            track->next   = cur_ptr;
            cur_ptr       = pre_ptr->next;
        }
        return cur_head;
    }
};

int main(int argc, char** argv) {
    Solution sol;

    return 0;
}