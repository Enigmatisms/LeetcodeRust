#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <unordered_map>
#include <unordered_set>

using namespace std;

/**
 * runtime: 100.0%
 * memory:  50.2%
 */
class MyQueue {
private:
    std::vector<int> st;
public:
    MyQueue() {}
    
    void push(int x) {
        std::vector<int> temp;
        while (st.empty() == false) {
            temp.emplace_back(st.back());
            st.pop_back();
        }
        st.push_back(x);
        while (temp.empty() == false) {
            st.emplace_back(temp.back());
            temp.pop_back();
        }
    }
    
    int pop() {
        int res = st.back();
        st.pop_back();
        return res;
    }
    
    int peek() const {
        return st.back();
    }
    
    bool empty() const {
        return st.empty();
    }
};


int main(int argc, char** argv) {

    return 0;
}