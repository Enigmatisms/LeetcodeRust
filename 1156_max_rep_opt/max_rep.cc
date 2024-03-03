#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <unordered_map>
#include <unordered_set>

using namespace std;

/**
 * runtime: 78.29%
 * memory:  28.95%
 */
class Solution {
public:
    int maxRepOpt1(string text) {
        int length = static_cast<int>(text.length()), result = 1;
        std::unordered_map<char, int> mapping;
        for (char v: text) {
            auto it = mapping.find(v);
            if (it != mapping.end())
                mapping[v] ++;
            else
                mapping[v] = 1;
        }
        for (int i = 1; i < length;) {
            char cval = text[i - 1];
            int j = i - 2;
            for (; j >= 0; j--) {
                if (text[j] != cval) break; 
            }
            int cur_len = i - j - int(text[i] != cval);
            result = std::max(result, std::min(cur_len + 1, mapping[cval]));
            for (j = i + 1; j < length; j++, cur_len++) {
                if (text[j] != cval) break; 
            }
            i = std::max(i + 1, j - 1);
            result = std::max(result, std::min(cur_len + 1, mapping[cval]));
        }
        return result;

    }
};

int main(int argc, char** argv) {
    Solution sol;
    std::string s = "bbababaaaa";
    
    printf("%d\n", sol.maxRepOpt1(s));
    return 0;
}