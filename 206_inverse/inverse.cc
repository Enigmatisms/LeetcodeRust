#include <iostream>
#include <vector>
#include <algorithm>
#include "../ListNode.hpp"

using namespace std;

/**
 * Easy AF
 * runtime: 80.12%
 * memory:  69.96%
 */
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        // 双指针
        if (!head || !head->next) return head;
        ListNode temp(0, head);
        ListNode* prev = &temp, *curr = head;
        while (curr) {
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        head->next = nullptr;
        return prev;
    }
};

int main(int argc, char** argv) {
    Solution sol;

    return 0;
}