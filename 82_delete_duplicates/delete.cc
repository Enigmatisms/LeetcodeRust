#include <iostream>
#include <vector>

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

/**
 * 实现还是太复杂了，并且AC依赖于debug（就是因为没有整体逻辑所以经常有漏考虑的）
 * 后面有些情况对你来说都不是很 intuitive 了。说明这个实现不好 
 * 需要理解题解
 * runtime: 92.77% 
 * memory:  53.93%
 */

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if (head == nullptr || head->next == nullptr) return head;
        int last_val = head->val;
        bool advance = false, head_dup = true;
        ListNode* dup_ptr = head, *ptr = head->next, *last_ptr = head, *ret_head = head;
        for (;ptr;ptr = ptr->next, last_ptr = last_ptr->next) {
            if (ptr->val == last_val) {
                do {
                    ptr = ptr->next;
                    last_ptr = last_ptr->next;
                } while (ptr && ptr->val == last_val);
                if (ptr)
                    last_val = ptr->val;
                else {
                    dup_ptr->next = nullptr;
                    advance = false;
                    break;
                }
                advance = true;
            } else {
                if (head_dup) {
                    head_dup = false;
                    advance = false;
                    dup_ptr = last_ptr;
                    ret_head = dup_ptr;
                }
                last_val = ptr->val;
                if (advance) {
                    dup_ptr->next = last_ptr;
                    dup_ptr = dup_ptr->next;
                } else {
                    advance = true;
                }
            }
        }
        if (advance) {
            if (head_dup) return last_ptr;          // fronts are all duplicated, only the last element is not duplicated
            dup_ptr->next = last_ptr;
        }
        return head_dup ? nullptr : ret_head;
    }
};

bool print_link(ListNode* head, int max_depth = 20) {
    for (int cnt = 0;head && cnt < max_depth;head = head->next, cnt ++) {
        printf("%d", head->val);
        if (head->next)
            printf("->");
        else {
            printf("\n");
            return true;
        }
    }
    return false;
}

int main() {
    std::vector<std::vector<int>> tests = {
        {1, 1, 3, 3, 4, 5, 6, 6, 7, 7, 8, 9},       
        {1, 3, 3, 4, 5, 6, 6, 7, 7, 8, 9},          
        {1, 3, 3, 4, 5, 6, 6, 7, 7, 8, 9, 9},       
        {3, 3, 3, 3},                               
        {3, 3, 3, 4, 4, 4},                         
        {3, 3, 3, 4, 5, 5, 5},                      
        {3, 3, 3, 4, 5, 5, 5, 6},                   
        {3, 4, 5, 6, 7, 8},
        {3, 3, 4, 4, 5, 5, 6, 6},
        {3, 3, 4, 4, 5, 5, 6, 6, 7},            // 0
        {7, 7},
        {7, 7, 8},                              // 0
        {6, 7, 7},  
        {6, 7, 8, 8, 9, 9, 10, 10, 11, 11},
    };
    std::vector<std::vector<ListNode>> node_list(tests.size());
    for (size_t i = 0; i < tests.size(); i++) {
        const std::vector<int>& test = tests[i];
        std::vector<ListNode>& nodes = node_list[i];
        nodes.resize(test.size());
        for (size_t j = 0; j < test.size(); j++) {
            nodes[j].val = test[j];
            nodes[j].next = (j + 1 == test.size()) ? nullptr : &nodes[j + 1];
        }
        print_link(&nodes[0]);
    }
    Solution sol;
    printf("Solution:\n");
    for (size_t i = 0; i < node_list.size(); i++) {
        auto res = sol.deleteDuplicates(&node_list[i][0]);
        printf("%lu: ", i + 1);
        if (print_link(res) == false) printf("\n");
    }
    return 0;
}