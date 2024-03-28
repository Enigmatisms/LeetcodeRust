#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <unordered_map>
#include <unordered_set>
#include "../../ListNode.hpp"

using namespace std;

/**
 * leetcode 92, 当时做过，用的是 O(n) 的内存复杂度。现在我用的是 O(1)
 * 很容易出 runtime 的问题
 * runtime: 100.00%
 * memory:  25.89%
 */
class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        if (!head || !head->next || m == n) return head;
        // write code here
        ListNode* rev_prev = nullptr;
        for (int i = 1; i < m; i++)
            rev_prev = rev_prev ? rev_prev->next : head;
        // previous node, current node, next node
        ListNode *pnode = rev_prev ? rev_prev->next : head, *cnode = pnode->next, *nnode = nullptr;
        pnode->next = nullptr;
        for (int i = m; i < n; i++) {
            nnode = cnode->next;
            cnode->next = pnode;
            pnode = cnode;
            cnode = nnode;
        }
        ListNode* new_tail = nullptr;
        if (rev_prev != nullptr) {      // 可以用 rev_prev->next 直接取做尾部
            new_tail = rev_prev->next;
            rev_prev->next = pnode;
        } else {                        // 否则需要回溯
            new_tail = pnode;
            while (new_tail->next)
                new_tail = new_tail->next;
            head = pnode;
        }
        new_tail->next = cnode;
        return head;
    }
};

int main(int argc, char** argv) {
    Solution sol;

    return 0;
}