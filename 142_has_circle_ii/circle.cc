#include <iostream>
#include <vector>
#include <algorithm>
#include "../ListNode.hpp"

using namespace std;

/**
 * 需要搞清楚里面的数学关系：快慢指针。当快慢指针之间的步长关系可以帮助求解此题
 * runtime: 94.65%
 * memory: 25.65%
 */
class Solution {
public:
    ListNode* detectCycle(ListNode *head) const noexcept {
        if (!head) return nullptr;
        ListNode *fptr = head, *sptr = head;      // fast and slow ptr
        do {
            fptr = fptr->next;
            if (!fptr) return nullptr;
            fptr = fptr->next;
            if (!fptr) return nullptr;
            sptr = sptr->next;
        } while (fptr != sptr);
        ListNode *track = head;
        while (track != sptr) {
            track = track->next;
            sptr  = sptr->next;
        }
        return track;
    }
};

int main(int argc, char** argv) {
    Solution sol;

    return 0;
}