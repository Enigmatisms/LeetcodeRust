#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <unordered_map>
#include <unordered_set>

using namespace std;

/**
 * 环形队列基于vector以及双指针实现
 * runtime: 98.65%
 * memory:  33.75%
 */
class MyCircularQueue {
public:
    MyCircularQueue(int k): storage(k, 0), head_ptr(0), tail_ptr(0), is_empty(true) {}
    
    bool enQueue(int value) {
        if (isFull()) return false;
        int size = static_cast<int>(storage.size());
        storage[tail_ptr] = value;
        if (++tail_ptr >= size)
            tail_ptr -= size;
        is_empty = false;
        return true;
    }
    
    bool deQueue() {
        if (isEmpty()) return false;
        int size = static_cast<int>(storage.size());
        if (++head_ptr >= size)
            head_ptr -= size;
        is_empty = tail_ptr == head_ptr;
        return true;
    }
    
    int Front() const {
        if (isEmpty()) return -1;
        return storage[head_ptr];
    }
    
    int Rear() const {
        if (isEmpty()) return -1;
        int ptr = tail_ptr - 1;
        if (ptr < 0)
            ptr += static_cast<int>(storage.size());
        return storage[ptr];
    }
    
    bool isEmpty() const {
        return is_empty;
    }
    
    bool isFull() const {
        return !is_empty && head_ptr == tail_ptr;
    }
public:
    std::vector<int> storage;
    int head_ptr;
    int tail_ptr;
    bool is_empty;
};

int main(int argc, char** argv) {
    MyCircularQueue queue(6);
    queue.enQueue(6);
    queue.Rear();
    queue.Rear();
    queue.deQueue();
    queue.enQueue(5);
    queue.Rear();
    queue.deQueue();
    queue.Front();
    printf("Queue: %d, %d, %d\n", queue.head_ptr, queue.tail_ptr, int(queue.is_empty));
    return 0;
}