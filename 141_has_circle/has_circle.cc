#include <iostream>
#include <vector>
#include <algorithm>
#include "../ListNode.hpp"

using namespace std;

/**
 * runtime: 99.61%
 * memory:  40.73%
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if (!head || !head->next) return false;
        ListNode *fptr = head->next, *sptr = head;      // fast and slow ptr
        while (fptr != sptr) {
            fptr = fptr->next;
            if (!fptr) return false;
            fptr = fptr->next;
            if (!fptr) return false;
            sptr = sptr->next;
        }
        return true;
    }
};

int main(int argc, char** argv) {
    Solution sol;

    return 0;
}