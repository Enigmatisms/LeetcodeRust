#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include "../ListNode.hpp"

using namespace std;

struct OrderFunctor {
    bool operator() (ListNode* n1, ListNode* n2) const {
        return n1->val > n2->val;
    }
};

/**
 * runtime: 94.15%
 * memory:  45.05%
 */
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode head;
        auto pred_func = OrderFunctor();
        std::priority_queue<ListNode*, std::vector<ListNode*>, OrderFunctor> pque(pred_func);
        for (ListNode* node: lists) {
            if (node == nullptr) continue;
            pque.emplace(node);
        }
        ListNode* ptr = &head;
        while (pque.empty() == false) {
            ListNode* node = pque.top();
            pque.pop();
            if (node->next)
                pque.emplace(node->next);
            ptr->next = node;
            ptr = ptr->next;
        }
        return head.next;
    }
};

int main(int argc, char** argv) {
    Solution sol;

    return 0;
}