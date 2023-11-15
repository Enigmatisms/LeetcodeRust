#include <iostream>
#include <vector>

/**
 * 我第一次碰见超过 NaN % 的情况.. 
 * runtime: 8ms (NaN) 估计是81.84%
 * memory:  25.51%
 */

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
        if (!head || !head->next) return head;
        ListNode* ptr = head->next, *dup_ptr = head;
        for (;ptr;ptr = ptr->next) {                    // 注意for循环退出条件
            while (ptr && ptr->val == dup_ptr->val) {
                ptr = ptr->next;
            }
            dup_ptr->next = ptr;
            if (ptr)
                dup_ptr = dup_ptr->next;
            else
                break;
        }
        return head;
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