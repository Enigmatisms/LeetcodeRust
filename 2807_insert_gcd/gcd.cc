#include "../ListNode.hpp"

/**
 * 简单题... 为啥说这是中等，从看题到写出来都不要5min
 * runtime: 99.69%
 * memory:  29.73%
 * 
 * 里面最值得记录的点: 欧几里得算法
*/

class Solution {
public:
    static int gcd(int a, int b) noexcept {
        while (b) {
            int tmp = a % b;
            a = b;
            b = tmp;
        }
        return a;
    }
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        if (!head || !head->next) return head;
        ListNode *ptr_f = head, *ptr_b = head->next;
        do {
            int gcd_v = gcd(ptr_f->val, ptr_b->val);
            ptr_f->next = new ListNode(gcd_v, ptr_b);
            ptr_f = ptr_b;
            ptr_b = ptr_b->next;
        } while (ptr_b != nullptr);
        return head;
    }
};

int main() {
    Solution sol;
    std::vector<std::vector<int>> tests{
        {18,6,10,3},
        {7},
        {10, 12, 16, 24, 16, 12, 10},
        {2, 3, 5, 7, 11, 13, 121}
    };
    for (const std::vector<int>& vec: tests) {
        std::vector<ListNode> nodes;
        create_link_list(vec, nodes);
        auto head = sol.insertGreatestCommonDivisors(&nodes.front());
        print_link(head);
    }
    return 0;
}