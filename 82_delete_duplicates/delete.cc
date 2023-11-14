#include <iostream>
#include <vector>

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if (head == nullptr || head->next == nullptr) return head;
        ListNode* new_head = head, *ptr = head->next, *keep = head;
        int last_val = head->val, head_val = head->val;
        while (ptr) {
            
            if (ptr->val == last_val) {
                
            }
        }
    }
};

int main() {

    return 0;
}