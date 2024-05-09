#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/**
 * runtime: 92.41%
 * memory:  67.58%
 */
class Solution {
public:
    int minLength(string s) {
        std::vector<char> stack;
        for (char v: s) {
            if (v == 'D' || v == 'B') {
                if (stack.empty() == false && stack.back() == v - 1) {
                    stack.pop_back();
                    continue;
                }
            }
            stack.push_back(v);
        }
        return static_cast<int>(stack.size());
    }
};

int main(int argc, char** argv) {
    Solution sol;

    return 0;
}