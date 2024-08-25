#include <iostream>
#include <vector>
#include <algorithm>
#include "../ListNode.hpp"

using namespace std;

/**
 * 题解的方法更妙，空间复杂度是 O(1)
 * 求链表中点，右半段原地反转，之后合并左半段和右半段
 * runtime: 86.71%
 * memory:  9.56%
 */
class Solution {
public:
    void reorderList(ListNode* head) {
        int cnt = 0;
        ListNode* sp = head;
        for (; sp != nullptr; cnt++)
            sp = sp->next;
        if (cnt < 3) return;
        int half_cnt = cnt >> 1;
        if (cnt & 1) half_cnt += 1; 
        std::vector<ListNode*> nodes;
        nodes.reserve(half_cnt);
        sp = head;
        for (int i = 0; sp != nullptr; i++, sp = sp->next) {
            if (i < half_cnt) continue;
            nodes.push_back(sp);
        }
        sp = head->next;
        while (true) {
            ListNode* top_node = nodes.back();
            nodes.pop_back();
            head->next = top_node;
            top_node->next = sp;
            if (nodes.empty()) {
                sp->next = nullptr;
                return;
            }
            head = sp;
            sp = sp->next;
        }
    }
};

int main(int argc, char** argv) {
    Solution sol;

    return 0;
}