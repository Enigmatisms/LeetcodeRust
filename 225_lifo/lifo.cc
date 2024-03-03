#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <unordered_map>
#include <unordered_set>
#include <queue>
/**
 * runtime: 100.00%
 * memory:  12.36%
*/
class MyStack {
private:
    std::queue<int> queue;
public:
    MyStack() {}
    
    void push(int x) {
        size_t old_elems = queue.size();
        queue.push(x);
        for (size_t i = 0; i < old_elems; i++) {
            int top_elem = queue.front();
            queue.pop();
            queue.push(top_elem);
        }
    }
    
    int pop() {
        int top_elem = queue.front();
        queue.pop();
        return top_elem;
    }
    
    int top() const {
        return queue.front();
    }
    
    bool empty() const {
        return queue.empty();
    }
};

/**
 * 这个实现是作弊了
 * runtime: 100.00%
 * memory:  39.93%
 */
class MyStack2 {
private:
    std::deque<int> queue;
public:
    MyStack2() {}
    
    void push(int x) {
        queue.push_back(x);
    }
    
    int pop() {
        int res = queue.back();
        queue.pop_back();
        return res;
    }
    
    int top() const {
        return queue.back();
    }
    
    bool empty() const {
        return queue.empty();
    }
};


int main(int argc, char** argv) {

    return 0;
}