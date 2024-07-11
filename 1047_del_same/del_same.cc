#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/**
 * 太简单了
 * runtime: 93.81%
 * memory:  63.90%
 */
class Solution {
public:
    string removeDuplicates(string s) {
        std::vector<char> stack;
        stack.reserve(s.size() + 1);
        stack.push_back(' ');
        for (char v: s) {
            if (stack.back() == v) {
                stack.pop_back();
            } else {
                stack.push_back(v);
            }
        }
        return std::string(stack.begin() + 1, stack.end());
    }
};

int main(int argc, char** argv) {
    Solution sol;

    return 0;
}