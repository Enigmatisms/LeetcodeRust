#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

/**
 * runtime: 85.97%
 * memory:  29.50%
 */
class Solution {
public:
    inline int singleNumber(const std::vector<int>& nums) const noexcept {
        return std::accumulate(nums.begin(), nums.end(), 0, [](int v1, int v2) {return v1 ^ v2;});
    }
};
int main(int argc, char** argv) {
    Solution sol;
    std::vector<int> testing = {2, 2, 4, 4, 3, 3, 5, 5, 7, 7, 1, 1, 0, 6, 6, 9, 9};
    printf("%d\n", sol.singleNumber(testing));
    return 0;
}