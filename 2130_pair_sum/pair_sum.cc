#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include "../ListNode.hpp"

using namespace std;

/**
 * 最简单的思路：数组出来，但是需要处理数组递增 reallocation 的问题
 * 稍微复杂一点（只能说这种是为了做题而做题）
 * 
 * 求中间位置（这种问题，就两次遍历即可）说是如此，但实际上脑残得很
 * 本来链表这种东西最好少用，要快就不要用链表，cache 性能太差了
 * 然后还反转链表... 这种虽然是原地的，但是...
 * 说真的刷题刷魔怔了就会这样。2130 是一道为了考算法而出的题，估计没有什么实际意义
 * runtime: 49.93%
 * memory:  56.34%
 */
class Solution {
public:
    // 如果是 deque 就还好（66.85%, 31.65%), vector 是速度最快的，但同时也是内存开销最大的
    // 傻逼题，明明可以 parallel reduction
    int pairSum(ListNode* head) const {
        std::vector<int> vals;
        for (; head; head = head->next)
            vals.push_back(head->val);
        int length = vals.size() >> 1, max_val = 0;
        auto sptr = vals.cbegin();
        auto eptr = vals.crbegin();
        for (int i = 0; i < length; i++) {
            max_val = std::max(max_val, (*sptr) + (*eptr));
            ++ sptr;
            ++ eptr;
        }
        return max_val;
    }

    // 两次遍历 + 反转链表
    int pairSum(ListNode* head) const {
        ListNode* ptr = head->next->next;
        int length = 2;
        for (; ptr; ++ length)
            ptr = ptr->next;
        length >>= 1;
        if (length == 1) return head->val + head->next->val;
        ptr = head->next;
        for (int i = 1; i < length; i++)
            ptr = ptr->next;
        ListNode *ptr_prev = ptr, *ptr_next;
        ptr = ptr->next;
        do {
            ptr_next = ptr->next;       // 记录 ptr 的下一个位置
            ptr->next = ptr_prev;       // ptr 指向前一个指针
            ptr_prev = ptr;             // 记录当前位置用于下一个指针反指的地址
            ptr = ptr_next;             // 当前指针去往下一个需要去的位置
        } while (ptr);
        // 此时 ptr_prev 将会是 尾部的起始节点
        int max_val = 0;
        for (int i = 0; i < length; i++) {
            max_val = std::max(head->val + ptr_prev->val, max_val);
            head = head->next;
            ptr_prev = ptr_prev->next;
        }
        return max_val;
    }
};

int main(int argc, char** argv) {
    Solution sol;

    return 0;
}