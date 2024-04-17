#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

/**
 * 
 * runtime: 81.74%
 * memory:  20.76%
 */
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        std::unordered_map<int, int> records;
        for (int i = 0; i < nums.size(); i++) {
            int num = nums[i];
            auto it = records.find(target - num);
            if (it == records.end()) 
                records[num] = i;
            else    
                return {it->second, i};
        }
        return {-1, -1};
    }
};

int main(int argc, char** argv) {
    Solution sol;

    return 0;
}