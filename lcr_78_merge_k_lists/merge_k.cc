#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include "../ListNode.hpp"

using namespace std;

/**
 * merge k 竟然是困难题目？
 * runtime: 60.71%
 * memory:  32.41%
 */

struct ListNodeCompFunctor {
    bool operator()(ListNode* n1, ListNode* n2) const {
        return n1->val > n2->val;
    }
};

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        std::priority_queue<ListNode*, std::vector<ListNode*>, ListNodeCompFunctor> queue;
        int list_len = lists.size();
        for (auto node: lists) {
            if (node) queue.emplace(node);
        }
        ListNode head, *ptr = &head;
        while (!queue.empty()) {
            auto small_node = queue.top();
            queue.pop();
            ptr->next = small_node;
            if (small_node->next) {
                queue.emplace(small_node->next);
            }
            ptr = ptr->next;
        }
        return head.next;
    }
};
int main(int argc, char** argv) {
    Solution sol;

    return 0;
}