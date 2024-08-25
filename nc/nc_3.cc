#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include "../ListNode.hpp"
using namespace std;

/**
 * 双指针 而且这里还有一个计算问题
 * 
 * runtime:
 * memory:
 */
class Solution {
public:
    ListNode* EntryNodeOfLoop(ListNode* pHead) {
        ListNode *fast = pHead, *slow = pHead;
        do {
            fast = fast->next;
            if (!fast) return nullptr;
            fast = fast->next;
            if (!fast) return nullptr;
            slow = slow->next;
        } while (fast != slow);
        fast = pHead;
        while (fast != slow) {
            fast = fast->next;
            slow = slow->next;
        }
        return fast;
    }
};

int main(int argc, char** argv) {
    Solution sol;

    return 0;
}