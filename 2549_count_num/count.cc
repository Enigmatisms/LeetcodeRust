#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/**
 * 这是我见过的最简单的题...
 * runtime: 100%
 * memory:  58.59%
 */
class Solution {
public:
    int distinctIntegers(int n) {
        return n - (n != 1);
    }
};

int main(int argc, char** argv) {
    Solution sol;

    return 0;
}