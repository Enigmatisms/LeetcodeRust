#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <unordered_map>
#include <unordered_set>

using namespace std;

/**
 * 顶级脑瘫题
 * runtime: 90.32%
 * memory:  26.43%
 */
class NumArray {
private:
    std::vector<int> prefix_sum;
public:
    NumArray(vector<int>& nums) {
        prefix_sum.resize(nums.size());
        std::partial_sum(nums.begin(), nums.end(), prefix_sum.begin());
    }
    
    int sumRange(int left, int right) {
        int result = prefix_sum[right];
        if (left)
            result -= prefix_sum[left - 1];
        return result;
    }
};

int main(int argc, char** argv) {

    return 0;
}