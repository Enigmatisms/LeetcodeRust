#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/**
 * 栈，简单题就是简单啊，秒做
 * runtime: 100.00%
 * memory:  38.14%
 */
class Solution {
public:
    std::string clearDigits(std::string s) const {
        std::string result;
        result.reserve(s.size());
        for (char c: s) {
            if (c <= '9') {
                if (!result.empty()) result.pop_back();
            } else {
                result.push_back(c);
            }
        }
        return result;
    }
};

int main(int argc, char** argv) {
    Solution sol;

    return 0;
}