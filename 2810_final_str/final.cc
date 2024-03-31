#include <iostream>
#include <vector>
#include <queue>

using namespace std;

/**
 * 双端队列很简单
 * runtime: 51.80%
 * memory:  5.57%
 */
class Solution {
public:
    string finalString(string s) {
        std::deque<char> queue;
        bool forward = true;
        for (char v: s) {
            if (v != 'i') {
                if (forward)
                    queue.emplace_back(v);
                else
                    queue.emplace_front(v);
            } else {
                forward = !forward;
            }
        }
        if (forward)
            return std::string(queue.cbegin(), queue.cend());
        return std::string(queue.crbegin(), queue.crend());
    }
};
int main(int argc, char** argv) {
    Solution sol;

    return 0;
}