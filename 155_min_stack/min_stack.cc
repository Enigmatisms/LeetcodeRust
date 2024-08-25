#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/**
 * 这道题可以说是 LRU 的基础 (最近最少使用的元素)
 * 设置一个栈存储最小值，另一个栈存储顺序值
 * 
 * 真恶心...
 * “面试的时候被问到不能用额外空间，就去网上搜了下不用额外空间的做法。思路是栈里保存差值。”
 * runtime: 94.53%
 * memory:  45.38%
 */
class MinStack {
private:
    std::vector<int> mins;
    std::vector<int> stack;

public:
    MinStack() {}
    
    void push(int val) {
        if (stack.empty())
            mins.push_back(val);
        else
            mins.push_back(std::min(mins.back(), val));
        stack.push_back(val);
    }
    
    void pop() {
        stack.pop_back();
        if (!stack.empty()) {
            mins.pop_back();
        }
    }
    
    int top() const {
        return stack.back();
    }
    
    int getMin() const {
        return mins.back();
    }
};

int main(int argc, char** argv) {
    return 0;
}