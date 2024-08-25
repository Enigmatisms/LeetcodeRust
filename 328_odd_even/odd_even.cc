#include <iostream>
#include <vector>
#include <algorithm>
#include "../ListNode.hpp"
using namespace std;

/**
 * 一遍过，非常简单
 * runtime: 96.82%
 * memory:  9.19%
 */
class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if (!head || !head->next) return head;
        ListNode *odd = head, *even = head->next, *even_head = even;
        do {
            if (even->next == nullptr) break;
            odd->next = even->next;
            odd = odd->next;
            if (odd->next == nullptr) break;
            even->next = odd->next;
            even = even->next;
        } while (true);
        even->next = nullptr;
        odd->next = even_head;
        return head;
    }
};

int main(int argc, char** argv) {
    Solution sol;

    return 0;
}