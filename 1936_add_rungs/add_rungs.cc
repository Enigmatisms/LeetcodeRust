#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/**
 * 
 * runtime: 87.60%
 * memory:  51.94%
 */
class Solution {
public:
    int addRungs(vector<int>& rungs, int dist) {
        int add_rungs = 0, prev_height = 0;
        for (int height: rungs) {
            int diff = height - prev_height;
            if (diff > dist) {
                add_rungs += (diff + dist - 1) / dist - 1;      // ceiling - 1
            }
            prev_height = height;
        }
        return add_rungs;
    }
};

int main(int argc, char** argv) {
    Solution sol;

    return 0;
}