#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <bitset>
#include <unordered_set>

using namespace std;

/**
 * 本题问题在于可能会写反，注意顺序
 * runtime: 98.96%
 * memory:  41.15%
 */
class Solution {
public: 
    int findKOr(vector<int>& nums, int k) {
        bool loop = false;
        std::vector<bool> bits; 
        do {
            int cnt = 0;
            loop = false;
            for (int& num: nums) {
                cnt += num & 1;
                num >>= 1;
                if (num) loop = true;
            }
            if (cnt >= k)
                bits.push_back(1);
            else
                bits.push_back(0);
        } while (loop);
        int result = 0;
        for (auto rit = bits.crbegin(); rit != bits.crend(); rit ++) {
            result <<= 1;
            result += int(*rit);
        }
        return result;
    }
};

int main(int argc, char** argv) {
    Solution sol;
    std::vector<int> nums = {14,7,12,9,8,9,1,15};
    int res = sol.findKOr(nums, 4);
    printf("result: %d -> ", res);
    std::cout << std::bitset<8>(res) << std::endl;
    return 0;
}