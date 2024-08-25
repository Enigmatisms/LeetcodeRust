#include "../ListNode.hpp"

/**
 * 本题很简单
 * runtime: 100.00%
 * memory:  5.6% (why)
 */

class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if (right == left || !head->next) return head;
        std::vector<ListNode*> stack;
        stack.reserve((right - left));
        ListNode* prev = nullptr, *next = nullptr, *cur = head, *ret_head = head;
        left--;
        for (int i = 1; cur != nullptr; i++, cur = cur->next) {
            if (i == left) prev = cur;
            else if (i == right + 1) next = cur;
            else if (i > left && i <= right) {       // push into the stack
                stack.push_back(cur);
            }
        }
        if (prev == nullptr) {
            if (stack.empty()) return ret_head;
            prev = stack.back();
            stack.pop_back();
            ret_head = prev;
        }
        for (; stack.empty() == false; prev = prev->next) {
            prev->next = stack.back();
            stack.pop_back();
        }
        prev->next = next;
        return ret_head;
    }
};

int main() {
    Solution sol;
    std::vector<std::vector<ListNode>> all_nodes(8);
    std::vector<std::vector<int>> all_vals = {
        {1, 2, 3, 4, 5, 6},
        {1, 2, 3, 4, 5},
        {1, 2, 3, 4, 5},
        {1, 2, 3, 4, 5},
        {1, 2, 3, 4},
        {1, 2, 3},
        {1, 2},
        {1},
    };
    std::vector<std::vector<int>> test_vals = {{2, 5}, {1, 4}, {2, 5}, {1, 5}, {2, 3}, {1, 2}, {1, 2}, {1, 1}};
    for (int i = 0; i < all_vals.size(); i++) {
        create_link_list(all_vals[i], all_nodes[i]);
    }
    for (int i = 0; i < 8; i++) {
        int start = test_vals[i].front(), ending = test_vals[i].back();
        print_link(sol.reverseBetween(&all_nodes[i][0], start, ending));
    }
    return 0;
}