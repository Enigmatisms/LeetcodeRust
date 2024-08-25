#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <array>

using namespace std;

/**
 * 这是用 unordered_map (此版本不予保留，见 leetcode 提交记录)
 * runtime: 22.31%
 * memory:  15.64%
 * 
 * 这是用 array<int, 26>
 * runtime: 99.36%
 * memory:  49.23%
 */
class Solution {
public:
    bool closeStrings(string word1, string word2) {
        // 长度不相同：死
        if (word1.length() != word2.length()) return false;
        std::array<int, 26> map1 = {0,}, map2 = {0,};
        for (char v: word1) ++ map1[v - 'a'];
        // word1 word2 存在不同的字符组成（不满足：“现有”这个条件），死
        for (char v: word2) ++ map2[v - 'a'];
        for (int i = 0; i < 26; i++) {
            int m1 = map1[i], m2 = map2[i];
            if ((m1 == 0 && m2 > 0) || (m1 > 0 && m2 == 0)) return false;
        }  
        // 现在保证了长度相等，且字符组成相等，现在只需要保证每个格子内部字符数一致就行
        std::sort(map1.begin(), map1.end());
        std::sort(map2.begin(), map2.end());
        for (int i = 0; i < 26; i++) {
            if (map1[i] != map2[i]) return false;
        }     
        return true;
    }
};

int main(int argc, char** argv) {
    Solution sol;

    return 0;
}