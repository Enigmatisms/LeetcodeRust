#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

/**
 * LRU 的实现应该基于双向链表 + Hash
 * 双向链表很容易出 bug (连接错了就会寄)
 * runtime: 95.14%
 * memory:  67.77%
 */

// 双向链表的实现
struct DLinkNode {
    DLinkNode* prev;
    DLinkNode* next;
    short key;
    int value;

    DLinkNode(int key = -1, int val = -1): prev(nullptr), next(nullptr), key(key), value(val) {}
    DLinkNode(DLinkNode* p, DLinkNode* n, int key, int val = -1): prev(p), next(n), key(key), value(val) {}
};

class LRUCache {
private:
    DLinkNode head;
    DLinkNode tail;
    std::unordered_map<int, DLinkNode*> mapping;
    short capacity;
public:
    LRUCache(int capacity): head(), tail(), capacity(capacity) {
        head.next = &tail;
        tail.prev = &head;
    }
    
    int get(int key) {
        auto it = mapping.find(key);
        if (it != mapping.end()) {
            auto node = it->second;
            node->prev->next = node->next;
            node->next->prev = node->prev;
            node->prev = &head;
            node->next = head.next;
            head.next->prev = node;
            head.next = node;
            return it->second->value;
        }
        return -1;
    }
    
    void put(int key, int value) {
        auto it = mapping.find(key);
        if (it == mapping.end()) {   // 判断 capacity, 插入队列首
            if (mapping.size() >= capacity) {   // 删除最近最少使用
                int end_key = tail.prev->key;
                tail.prev->prev->next = &tail;
                tail.prev = tail.prev->prev;
                mapping.erase(end_key);
            }
            DLinkNode* node = new DLinkNode(&head, head.next, key, value);
            head.next->prev = node;
            head.next = node;
            mapping.emplace(key, std::move(node));
        } else {                     // 移动到队首
            auto node = it->second;
            node->value = value;
            node->prev->next = node->next;
            node->next->prev = node->prev;
            node->prev = &head;
            node->next = head.next;
            head.next->prev = node;
            head.next = node;
        }
    }

    void print_link() const {
        auto ptr = head.next;
        printf("head ");
        while (ptr != nullptr) {
            if (ptr == &tail) {
                printf("-> tail\n");
            } else {
                printf("-> (%d, %d) ", ptr->key, ptr->value);
            }
            ptr = ptr->next;
        }
    }
    void print_link_reverse() const {
        auto ptr = tail.prev;
        printf("tail ");
        while (ptr != nullptr) {
            if (ptr == &head) {
                printf("-> head\n");
            } else {
                printf("-> (%d, %d) ", ptr->key, ptr->value);
            }
            ptr = ptr->prev;
        }
    }
};


int main(int argc, char** argv) {
    LRUCache sol(2);
    sol.put(1, 1);
    sol.put(2, 2);
    sol.print_link();
    sol.print_link_reverse();
    sol.get(1);
    printf("get 1\n");
    sol.print_link();
    sol.print_link_reverse();
    printf("put 3, 3\n");
    sol.put(3, 3);
    sol.print_link();
    sol.print_link_reverse();
    printf("get 2: %d\n", sol.get(2));
    printf("put 4, 4\n");
    sol.put(4, 4);
    sol.print_link();
    sol.print_link_reverse();
    return 0;
}