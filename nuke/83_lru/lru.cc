#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <unordered_map>
#include <unordered_set>

using namespace std;

/**
 * LRU 的思想是 Hash + 双向链表
 * LFU 的思想是 Hash + 双向链表数组
 * 已经写过一次了就没什么难的了
 * runtime:
 * memory:
 */

struct DLinkNode {
    DLinkNode(): prev(nullptr), next(nullptr), key(-1), value(0) {}
    DLinkNode(DLinkNode* prev, DLinkNode* next, int key = -1, int value = 0): 
        prev(prev), next(next), key(key), value(value) {}

    DLinkNode* prev;
    DLinkNode* next;
    int key;
    int value;
};

class Solution {
private:
    int capacity;
    DLinkNode head, tail;
    std::unordered_map<int, DLinkNode*> addrs;
public:
    Solution(int capacity): capacity(capacity) {
        addrs.reserve(capacity);
        head.next = &tail;
        tail.prev = &head;
    }

    ~Solution() {
        head.next = &tail;
        tail.prev = &head;
        for (auto [_, node_ptr]: addrs)
            delete node_ptr;
    }
 
    int get(int key) {
        auto it = addrs.find(key);
        if (it == addrs.end()) return -1;
        DLinkNode* ptr = it->second;

        ptr->prev->next = ptr->next;
        ptr->next->prev = ptr->prev;

        ptr->prev = tail.prev;
        ptr->next = &tail;

        tail.prev->next = ptr;
        tail.prev = ptr;
        return ptr->value;
    }
    
    void set(int key, int value){
        auto it = addrs.find(key);
        if (it == addrs.end()) {
            // first pop the head->next
            if (addrs.size() >= capacity) {
                DLinkNode* old_term = head.next;
                head.next = old_term->next;
                head.next->prev = &head;
                addrs.erase(old_term->key);
                delete old_term;
            }
            auto new_node = new DLinkNode(tail.prev, &tail, key, value);
            tail.prev->next = new_node;
            tail.prev = new_node;
            addrs.emplace(key, std::move(new_node));
        } else {
            DLinkNode* ptr = it->second;
            ptr->value = value;

            ptr->prev->next = ptr->next;
            ptr->next->prev = ptr->prev;

            ptr->prev = tail.prev;
            ptr->next = &tail;

            tail.prev->next = ptr;
            tail.prev = ptr;
        }
    }
};

int main(int argc, char** argv) {
    Solution sol(5);

    return 0;
}