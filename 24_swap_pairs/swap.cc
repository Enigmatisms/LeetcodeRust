#include <iostream>
#include <vector>
// Definition for singly-linked list.
/**
 * So simple...
 * 0ms 100% (run-time)
 * 7.85 MB 5.12% (memory)
*/
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if (head == nullptr || head->next == nullptr) {
            return head;
        }
        ListNode *ptr1 = head, *ptr2 = head->next, *new_head = head->next, *last_ptr = nullptr;
        while (true) {
            if (last_ptr != nullptr)
                last_ptr->next = ptr2;
            ptr1->next = ptr2->next;
            ptr2->next = ptr1;
            last_ptr = ptr1;
            ptr1 = ptr1->next;
            if (ptr1 == nullptr || ptr1->next == nullptr)
                return new_head;
            ptr2 = ptr1->next;
        }
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
    constexpr int num_nodes = 2;
    std::vector<ListNode> nodes_1(num_nodes);
    for (int i = 0; i < num_nodes; i++) {
        nodes_1[i] = ListNode(i);
    }
    for (int i = 0; i < num_nodes - 1; i++) {
        nodes_1[i].next = &nodes_1[i + 1];
    }
    
    Solution::print_list_nodes(&nodes_1.front());

    Solution sol;
    auto res = sol.swapPairs(&nodes_1.front());
    Solution::print_list_nodes(res);
    return 0;
}