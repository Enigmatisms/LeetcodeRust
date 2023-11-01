#include <iostream>
// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

/**
 * Too fucking easy I believe
 * runtime: 61.70%
 * memory:  21.64%
 */

class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) const {
        if (k == 0 || head == nullptr || head->next == nullptr) return head;
        ListNode *ptr = head->next;
        int length = 2;
        for (; ptr->next != nullptr; ptr = ptr->next, length++) {}
        k %= length;
        if (k > 0) {
            ptr->next = head;
            ListNode *new_ptr = head;
            for (int i = k + 1; i < length; i++, new_ptr = new_ptr->next) {}
            ListNode* new_head = new_ptr->next;
            new_ptr->next = nullptr;
            return new_head;
        } else {
            return head;
        }
    }
};

void print_nodes(ListNode* head) {
    while (head != nullptr) {
        printf("%d->", head->val);
        head = head->next;
    }
    printf("Done\n");
}

int main(int argc, char** argv) {
    ListNode nodes[10];;
    for (int i = 0; i < 9; i++) {
        nodes[i].val = i + 1;
        nodes[i].next = &nodes[i+1];
    }
    nodes[9] = 10;
    nodes[9].next = nullptr;
    print_nodes(&nodes[0]);
    Solution sol;
    int val = argc > 1 ? atoi(argv[1]) : 3;
    auto new_head = sol.rotateRight(&nodes[0], val);
    print_nodes(new_head);
    return 0;
}