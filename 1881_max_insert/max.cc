#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <unordered_map>
#include <unordered_set>

using namespace std;

/**
 * 这tm是简单题吧... 一点难度都没有啊
 * runtime: 98.92%
 * memory:  67.74%
 */
class Solution {
public:
    string maxValue(string n, int x) {
        char cx = '0' + x;
        size_t i = 0;
        if (n.front() != '-') {
            for (; i < n.size(); i++) {
                if (n[i] < cx) {
                    n.insert(n.begin() + i, cx);
                    break;
                }
            }
            if (i == n.size())
                n.push_back(cx);
        } else {
            for (i = 1; i < n.size(); i++) {
                if (n[i] > cx) {
                    n.insert(n.begin() + i, cx);
                    break;
                }
            }
            if (i == n.size())
                n.push_back(cx);
        }
        return n;
    }
};

int main(int argc, char** argv) {
    Solution sol;

    return 0;
}