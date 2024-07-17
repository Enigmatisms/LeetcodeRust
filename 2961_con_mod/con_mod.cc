#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int64_t pow_mod(int64_t a, int64_t b, int64_t m) {
    // a, b, m are all limited, and b here will be positive
    int64_t res = 1;
    a %= m;
    for (; b; b >>= 1) {
        if (b & 1) {
            res = (res * a) % m;
        }
        a = (a * a) % m;
    }
    return res;
}   

/**
 * 
 * runtime: 79.14%
 * memory:  5.52%
 */
class Solution {
public:
    vector<int> getGoodIndices(vector<vector<int>>& variables, int target) {
        std::vector<int> result;
        result.reserve(variables.size());
        for (size_t i = 0; i < variables.size(); i++) {
            auto& vars = variables[i];
            if (pow_mod(pow_mod(vars[0], vars[1], 10), vars[2], vars[3]) == target)
                result.push_back(i);
        }
        return result;
    }
};

int main(int argc, char** argv) {
    Solution sol;
    
    return 0;
}