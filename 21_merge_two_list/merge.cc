#include <iostream>
#include <vector>

/**
 * Merge sorted linked-list. This is not an easy task to do in Rust since the linked list in Rust is not easy to implement
 * 92.35% speed
 * 5.4% memory
*/

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) const {
        ListNode* head_ptr = nullptr;
        if (list1 == nullptr) return list2;
        else if (list2 == nullptr) return list1;
        ListNode* ptr1 = list1, *ptr2 = list2, *new_ptr = nullptr;
        if (list1->val <= list2->val) {
            head_ptr = list1;
            ptr1 = ptr1->next;
        } else {
            head_ptr = list2;
            ptr2 = ptr2->next;
        }
        new_ptr = head_ptr;
        while (ptr1 && ptr2) {
            if (ptr1->val <= ptr2->val) {
                new_ptr->next = ptr1;
                new_ptr = ptr1;
                ptr1 = ptr1->next;
            } else {
                new_ptr->next = ptr2;
                new_ptr = ptr2;
                ptr2 = ptr2->next;
            }
        }
        if (ptr1 == nullptr) {
            new_ptr->next = ptr2;
        } else {
            new_ptr->next = ptr1;
        }
        return head_ptr;
    }

    static void print_list_nodes(ListNode* head) {
        while (head != nullptr) {
            if (head->next != nullptr) {
                printf("%d->", head->val);
            } else {
                printf("%d\n", head->val);
                break;
            }
            head = head->next;
        }
    }
};

int main() {
    std::vector<ListNode> nodes_1(8), nodes_2(6);
    int vals[6] = {0, 1, 1, 2, 4, 4};
    for (int i = 0; i < 8; i++) {
        nodes_1[i] = ListNode(i);
    }
    for (int i = 0; i < 7; i++) {
        nodes_1[i].next = &nodes_1[i + 1];
    }

    for (int i = 0; i < 6; i++) {
        nodes_2[i] = ListNode(vals[i]);
    }
    for (int i = 0; i < 5; i++) {
        nodes_2[i].next = &nodes_2[i + 1];
    }
    
    Solution sol;
    printf("started.\n");
    auto res = sol.mergeTwoLists(&nodes_1.front(), &nodes_2.front());
    printf("completed.\n");
    Solution::print_list_nodes(res);
    return 0;
}