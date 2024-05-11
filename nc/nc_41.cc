#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <unordered_map>

using namespace std;

/**
 * runtime:
 * memory:
 */
class Solution {
public:
    int maxLength(vector<int>& arr) {
        int length = arr.size(); 
        if (length == 0) return 0;
        int sptr = 0, eptr = 1, max_len = 1;
        std::unordered_map<int, int> in_range;
        in_range.emplace(arr[0], 0);
        for (; eptr < length; ) {
            int val = arr[eptr];
            auto it = in_range.find(val);
            if (it == in_range.end()) {
                in_range[val] = eptr ++;
                max_len = std::max(max_len, eptr - sptr);
            } else {
                sptr = it->second;
                for (auto it = in_range.begin(); it != in_range.end();) {
                    if (it->second < sptr) {
                        it = in_range.erase(it);
                    } else {
                        ++ it;
                    }
                }
                it->second = eptr ++;
                sptr ++;
            }
        }
        return max_len;
    }
};

int main(int argc, char** argv) {
    Solution sol;

    return 0;
}