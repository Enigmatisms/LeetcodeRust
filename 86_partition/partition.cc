#include <vector>
#include "../ListNode.hpp"

/**
 * 这道题想法挺简单的 
 * runtime: 85.71%
 * memory:  36.29%
 */

class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        if (head == nullptr || head->next == nullptr) return head;
        ListNode* first_p = nullptr, *second_p = nullptr, *ptr = head->next; 
        ListNode* first_h = nullptr, *second_h = nullptr; 
        if (head->val < x) {
            first_p = head;
            first_h = head;
        } else {
            second_p = head;
            second_h = head;
        }
        while (ptr) {
            if (ptr->val < x) {
                if (first_p) {
                    first_p->next = ptr;
                    first_p = first_p->next;
                } else {
                    first_p = ptr;
                    first_h = ptr;
                }
            } else {
                if (second_p) {
                    second_p->next = ptr;
                    second_p = second_p->next;
                } else {
                    second_p = ptr;
                    second_h = ptr;
                }
            }
            ptr = ptr->next;
        }
        if (second_p)
            second_p->next = nullptr;
        if (first_p) {
            first_p->next = second_h;
            return first_h;
        }
        return second_h;
    }
};

int main() {
    std::vector<std::vector<ListNode>> all_nodes(6);
    std::vector<std::vector<int>> all_vals = {
        {1, 4, 3, 2, 5, 2},
        {1, 5, 6, 2, 3, 4, 7, 2, 6, 3, 5, 2, 3, 3, 5, 5, 3},
        {5, 5, 5, 4, 4, 4, 3, 3, 3, 2, 2, 2},
        {1, 1},
        {9, 8, 7, 6, 5, 4, 3, 2, 1},
        {9, 9, 9, 8, 8, 2, 2, 7, 7, 6, 6, 4, 4, 4, 5, 5, 8, 8},
    };
    std::vector<int> test_vals = {3, 4, 3, 2, 5, 7};
    for (int i = 0; i < 6; i++) {
        create_link_list(all_vals[i], all_nodes[i]);
    }
    Solution sol;
    for (int i = 0; i < 6; i++) {
        auto res = sol.partition(&all_nodes[i][0], test_vals[i]); 
        printf("Solution %d: ", i + 1);
        print_link(res);
    }
    return 0;
}