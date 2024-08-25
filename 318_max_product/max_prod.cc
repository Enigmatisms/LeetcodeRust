#include <iostream>
#include <vector>

/**
 * 这道题超级傻逼... 位masking完全可以直接做，但我想了半天怎么找一个非O(n^2)的方法...
 * 结果答案告诉我没有，就是 O(n^2).. 我傻了
 * runtime: 96.04%
 * memory:  35.42%
 */

class Solution {
public:
    int maxProduct(const std::vector<std::string>& words) const {
        int length = words.size();
        std::vector<int> masks(length);
        for (int i = 0; i < length; i++) {
            std::string word = words[i];
            int wordLength = word.size();
            for (int j = 0; j < wordLength; j++) {
                masks[i] |= 1 << (int(word[j]) - 97);
            }
        }
        int maxProd = 0;
        for (int i = 0; i < length; i++) {
            int mask_i = masks[i];
            for (int j = i + 1; j < length; j++) {
                if ((mask_i & masks[j]) == 0) {
                    maxProd = std::max(maxProd, int(words[i].size() * words[j].size()));
                }
            }
        }
        return maxProd;
    }
};

int main() {
    Solution sol;
    std::vector<std::string> test{"abcw","baz","foo","bar","xtfn","abcdef"};
    printf("max product: %d\n", sol.maxProduct(test));
    return 0;
}